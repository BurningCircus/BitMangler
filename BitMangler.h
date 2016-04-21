//BitMangler.h
//Zach Hummel
//1/7/16

//Bit Mangler
//A sound design tool which uses bit shifting, bitcrushing, waveshaping,
//and other methods to create low-fidelity audio mayhem.
//Developed using JUCE.

//Includes and dependencies
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PI 3.14159265359

class BitMangler {
public:
	//Constructor/destructor
	BitMangler();
	BitMangler(int projectBitDepth);
	~BitMangler();

	//Getters/setters
	float getInputGain() {
		return m_inGain;
	}

	float getOutputGain() {
		return m_outGain;
	}

	int getShift() {
		return m_shift;
	}

	int getTargetBitDepth() {
		return m_targetBitDepth;
	}
	
	float getLPFreq() {
	    return m_lpFreq;
	}
	
	float getHPFreq() {
	    return m_hpFreq;
	}
	
	float getDrive() {
	    return m_drive;
	}
	
	float getError() {
	    return m_error;
	}

	void setInputGain(float gain);
	void setOutputGain(float gain);
	void setShift(int bits);
	void setTargetBitDepth(int bitDepth);
	void setLPFreq(float freq);
	void setHPFreq(float freq);
	void setLPEnabled(bool enabled);
	void setHPEnabled(bool enabled);
	void setDrive(float drive);
	void setError(float error);

	//Use functions
	void applyInputGain(float *leftSample, float *rightSample);
	void applyOutputGain(float *leftSample, float *rightSample);
	void bitShift(float *leftSample, float *rightSample);
	void bitCrush(float *leftSample, float *rightSample);
	void LPFilter(float *leftSample, float *rightSample, double sampleRate);
	void HPFilter(float *leftSample, float *rightSample, double sampleRate);
	void flushLPBuffers();
	void flushHPBuffers();
	void hardClip(float *leftSample, float *rightSample);
	void softClip(float *leftSample, float *rightSample);
	void applyError(float *leftsample, float *rightSample);

private:
	//Member data
	float m_inGain, m_outGain; //Input and output gain. All gain values in linear decimal form, not decibel scale.
	int m_shift; //The number of bits by which to shift incoming audio.
	bool m_lWraparound; //Flag to detect bit wraparound for the left channel.
	bool m_rWraparound; //Flag to detect bit wraparound for the right channel.
	int m_targetBitDepth; //The bit depth to which we will re-quantize incoming audio.
	int m_projectBitDepth; //The bit depth of the project for use with bit-shifting math.
	float m_hpFreq, m_lpFreq; //Corner frequencies for the hp/lp filters.
	float m_drive; //Gain for driving the clipping stage.
	float m_error; //Error to be introduced in the signal as a percentage (0.0 - 1.0).
	float m_lastLeftSample, m_lastRightSample;
	
	//A pile of short buffers for hp/lp filters.
	//The buffers are short enough that they could just be individual variables, but this is easier to organize.
	float lpInputL[2], lpInputR[2], lpOutputL[2], lpOutputR[2], hpInputL[2], hpInputR[2], hpOutputL[2], hpOutputR[2];

	//Private getters/setters
	bool getLeftWraparound() {
		return m_lWraparound;
	}

	bool getRightWraparound() {
		return m_rWraparound;
	}

	int getProjectBitDepth() {
		return m_projectBitDepth;
	}
	
	float getLastLeftSample() {
	    return m_lastLeftSample;
	}

	float getLastRightSample() {
	    return m_lastRightSample;
	}
	
	void setLeftWraparound(bool wrap);
	void setRightWraparound(bool wrap);
	void setLastLeftSample(float sample);
	void setLastRightSample(float sample);

	//Private use functions
	float round(float x) {
		return x >= 0.0f ? floorf(x + 0.5f) : ceilf(x - 0.5f);
	}
};