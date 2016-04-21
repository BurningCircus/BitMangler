//BitMangler.cpp
//Zach Hummel
//1/7/16

//Implementation of BitMangler.h

#include "BitMangler.h"

//Constructor/Destructor
BitMangler::BitMangler() {
	//Initialize settings
	m_projectBitDepth = 24;
	setInputGain(1.0f); //Unity gain
	setOutputGain(1.0f); //Unity gain
	setShift(0); //No shifting
	setLeftWraparound(false);
	setRightWraparound(false);
	setTargetBitDepth(getProjectBitDepth()); //match project bit depth
	setLPFreq(20000.0f); //20kHz
	setHPFreq(5.0f); //5Hz
	setDrive(1.0f); //Unity gain
	setLastLeftSample(0.0f);
	setLastRightSample(0.0f);
	setError(0.0f); //no error
	
	//Flush filter buffers
	flushLPBuffers();
	flushHPBuffers();
	
	//Seed random number generator
	srand(time(NULL));
}

BitMangler::BitMangler(int projectBitDepth) {
	//Initialize settings
	m_projectBitDepth = projectBitDepth;
	setInputGain(1.0f); //Unity gain
	setOutputGain(1.0f); //Unity gain
	setShift(0); //No shifting
	setLeftWraparound(false);
	setRightWraparound(false);
	setTargetBitDepth(getProjectBitDepth()); //match project bit depth
	setLPFreq(20000.0f); //20kHz
	setHPFreq(5.0f); //5Hz
	setDrive(1.0f); //Unity gain
	setLastLeftSample(0.0f);
	setLastRightSample(0.0f);
	setError(0.0f); //no error
	
	//Flush filter buffers
	flushLPBuffers();
	flushHPBuffers();
	
	//Seed random number generator
	srand(time(NULL));
}

BitMangler::~BitMangler() {}

//Getters/setters
void BitMangler::setInputGain(float gain) {
	m_inGain = gain;
}

void BitMangler::setOutputGain(float gain) {
	m_outGain = gain;
}

void BitMangler::setShift(int bits) {
	m_shift = bits;
}

void BitMangler::setTargetBitDepth(int bitDepth) {
	m_targetBitDepth = bitDepth;
}

void BitMangler::setHPFreq(float freq) {
    m_hpFreq = freq;
}

void BitMangler::setLPFreq(float freq) {
    m_lpFreq = freq;
}

void BitMangler::setDrive(float drive) {
    m_drive = drive;
}

void BitMangler::setError(float error) {
    m_error = error;
}

//Private getters/setters
void BitMangler::setLeftWraparound(bool wrap) {
	m_lWraparound = wrap;
}

void BitMangler::setRightWraparound(bool wrap) {
	m_rWraparound = wrap;
}

void BitMangler::setLastLeftSample(float sample) {
    m_lastLeftSample = sample;
}

void BitMangler::setLastRightSample(float sample) {
    m_lastRightSample = sample;
}

//Use functions
void BitMangler::applyInputGain(float *leftSample, float *rightSample) {
	//Apply input gain.
	*leftSample = *leftSample * getInputGain();
	*rightSample = *rightSample * getInputGain();
}

void BitMangler::applyOutputGain(float *leftSample, float *rightSample) {
	//Apply output gain.
	*leftSample = *leftSample * getOutputGain();
	*rightSample = *rightSample * getOutputGain();
}

void BitMangler::flushLPBuffers() {
    //Zero the LP filter buffers
	for(int i = 0; i < 2; ++i) {
	    lpInputL[i] = 0.0f;
	    lpInputR[i] = 0.0f;
	    lpOutputL[i] = 0.0f;
	    lpOutputR[i] = 0.0f;
	}
}

void BitMangler::flushHPBuffers() {
    //Zero the HP filter buffers
	for(int i = 0; i < 2; ++i) {
	    hpInputL[i] = 0.0f;
	    hpInputR[i] = 0.0f;
	    hpOutputL[i] = 0.0f;
	    hpOutputR[i] = 0.0f;
	}
}

//The bit-shifting code. Shifts one sample per channel by one bit.
//Loop as necessary.

//DEPRECATED.
void BitMangler::bitShift(float *leftSample, float *rightSample) {
	bool leftWrapThisTime = getLeftWraparound();
	bool rightWrapThisTime = getRightWraparound();

	//Add 1.0 to our inputs to scale [-1.0, 1.0] to [0.0, 2.0].
	//Multiply result by 2^(bitDepth-1) - 0.5 to scale [0.0, 2.0] to [0, 2^(bitDepth) - 1].
	//This gives us our (unsigned) value range, which we can then do math on to shift bits.
	long left = (long) ((*leftSample + 1.0f) * (pow(2.0f, getProjectBitDepth() - 1)) - 0.5f);
	long right = (long) ((*rightSample + 1.0f) * (pow(2.0f, getProjectBitDepth() - 1)) - 0.5f);

	//Determine whether or not there will be bit wraparound into the next sample
	if(left%2 != 0) {
		setLeftWraparound(true);
	} else {
		setLeftWraparound(false);
	}

	if(right%2 != 0) {
		setRightWraparound(true);
	} else {
		setRightWraparound(false);
	}

	//Divide by 2 to actually shift bits. This will leave a 0 in the most significant bit.
	left = left/2;
	right = right/2;

	//If there is bit wraparound this time, toggle the most significant bit.
	if(leftWrapThisTime) {
		left = left + (long) pow(2.0f, (getProjectBitDepth() - 1));
	}
	if(rightWrapThisTime) {
		right = right + (long) pow(2.0f, (getProjectBitDepth() - 1));
	}

	//Revert back from [0, 65535] scale to [-1.0, 1.0] scale samples.
	//This is the format required for our output samples.
	*leftSample = (float) left / (pow(2.0f, getProjectBitDepth() - 1) - 0.5f) - 1.0f;
	*rightSample = (float) right / (pow(2.0f, getProjectBitDepth() - 1) - 0.5f) - 1.0f;
}

//The bitcrushing code. Crushes one sample per channel at a time.
//Loop as necessary.
void BitMangler::bitCrush(float *leftSample, float *rightSample) {
	//Quantize to target bit depth to introduce quantization error.
	long left = (long) round((*leftSample + 1.0f) * (pow(2.0f, getTargetBitDepth()) - 1));
	long right = (long) round((*rightSample + 1.0f) * (pow(2.0f, getTargetBitDepth()) - 1));

	//Divide out the max integer of the target bit depth
	//to leave the quantized amplitude values.
	*leftSample = ((float) left) / (pow(2.0f, getTargetBitDepth()) - 1) - 1.0f;
	*rightSample = ((float) right) / (pow(2.0f, getTargetBitDepth()) - 1) - 1.0f;
}

//Apply low-pass filter 
void BitMangler::LPFilter(float *leftSample, float *rightSample, double sampleRate) {
    //Calculate intermediaries
    float leftInput = *leftSample;
    float rightInput = *rightSample;
    float w0 = 2 * PI * getLPFreq() / sampleRate;
    float alpha = sin(w0) / 2 * (.707); //Fixed Q for maximum flat amplitude below f0
    float cosw0 = cos(w0); //Minor optimization
    
    //Calculate coefficients
	float b0 = (1 - cosw0)/2;
	float b1 = 1 - cosw0;
	float b2 = b0;
	float a0 = 1 + alpha;
	float a1 = -2 * cosw0;
	float a2 = 1 - alpha;
	
	//Apply filtering
	*leftSample = (b0/a0)*leftInput + (b1/a0)*lpInputL[0] + (b2/a0)*lpInputL[1] - (a1/a0)*lpOutputL[0] - (a2/a0)*lpOutputL[1];
	*rightSample = (b0/a0)*rightInput + (b1/a0)*lpInputR[0] + (b2/a0)*lpInputR[1] - (a1/a0)*lpOutputR[0] - (a2/a0)*lpOutputR[1];

    //Rotate buffers
    lpInputL[1] = lpInputL[0];
    lpInputL[0] = leftInput;
    lpInputR[1] = lpInputR[0];
    lpInputR[0] = rightInput;
    lpOutputL[1] = lpOutputL[0];
    lpOutputL[0] = *leftSample;
    lpOutputR[1] = lpOutputR[0];
    lpOutputR[0] = *rightSample;
}

//Apply high-pass filter
void BitMangler::HPFilter(float *leftSample, float *rightSample, double sampleRate) {
    //Calculate intermediaries
    float leftInput = *leftSample;
    float rightInput = *rightSample;
    float w0 = 2 * PI * getHPFreq() / sampleRate;
    float alpha = sin(w0) / 2 * (.707); //Fixed Q for maximum flat amplitude above f0
    float cosw0 = cos(w0); //Minor optimization
    
    //Calculate coefficients
	float b0 = (1 + cosw0)/2;
	float b1 = -(1 + cosw0);
	float b2 = b0;
	float a0 = 1 + alpha;
	float a1 = -2 * cosw0;
	float a2 = 1 - alpha;
	
	//Apply filtering
	*leftSample = (b0/a0)*leftInput + (b1/a0)*hpInputL[0] + (b2/a0)*hpInputL[1] - (a1/a0)*hpOutputL[0] - (a2/a0)*hpOutputL[1];
	*rightSample = (b0/a0)*rightInput + (b1/a0)*hpInputR[0] + (b2/a0)*hpInputR[1] - (a1/a0)*hpOutputR[0] - (a2/a0)*hpOutputR[1];

    //Rotate buffers
    hpInputL[1] = hpInputL[0];
    hpInputL[0] = leftInput;
    hpInputR[1] = hpInputR[0];
    hpInputR[0] = rightInput;
    hpOutputL[1] = hpOutputL[0];
    hpOutputL[0] = *leftSample;
    hpOutputR[1] = hpOutputR[0];
    hpOutputR[0] = *rightSample;   
}

//Apply hard clipping (digital clipping)
void BitMangler::hardClip(float *leftSample, float *rightSample) {
    //Input gain (drive)
    *leftSample = *leftSample * getDrive();
    *rightSample = *rightSample * getDrive();

    if(*leftSample > 1.0f) {
        *leftSample = 1.0f;
    }
    
    if(*rightSample > 1.0f) {
        *rightSample = 1.0f;
    }
    
    //Auto gain reduction.
    *leftSample = *leftSample * (1 / getDrive());
    *rightSample = *rightSample * (1 / getDrive());
}

//Apply soft clipping using tanh(x).
void BitMangler::softClip(float *leftSample, float *rightSample) {
    //Input gain (drive)
    *leftSample = *leftSample * getDrive();
    *rightSample = *rightSample * getDrive();
    
    *leftSample = tanh(*leftSample);
    *rightSample = tanh(*rightSample);
    
    //Auto gain reduction.
    *leftSample = *leftSample * (1 / getDrive());
    *rightSample = *rightSample * (1 / getDrive());
}

//An original algorithm design to simulate sample-and-hold errors at the ADC stage.
void BitMangler::applyError(float *leftSample, float *rightSample) {
    float randL = (rand() % 101) / 100.0f;
    float randR = (rand() % 101) / 100.0f;
    
    //If we have randomly chosen this sample, apply error to it via sample-and-hold.
    if(randL < getError()) {
        *leftSample = getLastLeftSample();
    } else {
        setLastLeftSample(*leftSample);
    }
    
    if(randR < getError()) {
        *rightSample = getLastRightSample();
    } else {
        setLastRightSample(*rightSample);
    }
}