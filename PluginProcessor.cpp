/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
BitManglerAudioProcessor::BitManglerAudioProcessor()
{
	//Initialize the plugin code.
	mBitMangler = BitMangler(24);

    //Set starting values for all parameters here.
    userParams[bypass] = 0.0f; //not bypassed
    userParams[inGain] = 1.0f; //unity gain
    userParams[outGain] = 1.0f; //unity gain
    userParams[shift] = 0.0f; //no bit shifting
    userParams[targetBitDepth] = 24; //24-bit max, which should be plenty
    userParams[lpFreq] = 20000.0f; //20kHz
    userParams[hpFreq] = 5.0f; //5Hz
    userParams[lpEnabled] = 0.0f; //not enabled
    userParams[hpEnabled] = 0.0f; //not enabled
    userParams[drive] = 1.0f; //unity gain
    userParams[error] = 0.0f; //no error
    userParams[clip] = 0.0f; //hard clip
    
    //Push parameters.
    setParameter(inGain, userParams[inGain]);
    setParameter(outGain, userParams[outGain]);
    setParameter(shift, userParams[shift]);
    setParameter(targetBitDepth, userParams[targetBitDepth]);
    setParameter(lpFreq, userParams[lpFreq]);
    setParameter(hpFreq, userParams[hpFreq]);
    setParameter(lpEnabled, userParams[lpEnabled]);
    setParameter(hpEnabled, userParams[hpEnabled]);
    setParameter(drive, userParams[drive]);
    setParameter(error, userParams[error]);
    setParameter(clip, userParams[clip]);
}

BitManglerAudioProcessor::~BitManglerAudioProcessor()
{
}

//==============================================================================
const String BitManglerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int BitManglerAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float BitManglerAudioProcessor::getParameter (int index)
{
    switch(index) {
        case bypass:
            return userParams[bypass];
        case inGain:
            userParams[inGain] = mBitMangler.getInputGain();
            return userParams[inGain];
        case outGain:
            userParams[outGain] = mBitMangler.getOutputGain();
            return userParams[outGain];
        case shift:
            userParams[shift] = (float) mBitMangler.getShift();
            return userParams[shift];
        case targetBitDepth:
            userParams[targetBitDepth] = (float) mBitMangler.getTargetBitDepth();
            return userParams[targetBitDepth];
        case lpFreq:
            userParams[lpFreq] = mBitMangler.getLPFreq();
            return userParams[lpFreq];
        case hpFreq:
            userParams[hpFreq] = mBitMangler.getHPFreq();
            return userParams[hpFreq];
        case lpEnabled:
            return userParams[lpEnabled];
        case hpEnabled:
            return userParams[hpEnabled];
        case drive:
            userParams[drive] = mBitMangler.getDrive();
            return userParams[drive];
        case error:
            userParams[error] = mBitMangler.getError();
            return userParams[error];
        case clip:
            return userParams[clip];
        default:
            //invalid index.
            return 0.0f;
    }
}

void BitManglerAudioProcessor::setParameter (int index, float newValue)
{
    switch(index) {
        case bypass:
            if(newValue >= 1.0f) {
                userParams[bypass] = 1.0f;
            } else {
                userParams[bypass] = 0.0f;
            }
            break;
        case inGain:
            if(newValue < 0.0f) {
                userParams[inGain] = 0.0f;
                mBitMangler.setInputGain(userParams[inGain]);
                break;
            } else {
                userParams[inGain] = newValue;
                mBitMangler.setInputGain(userParams[inGain]);
                break;
            }
        case outGain:
            if(newValue < 0.0f) {
                userParams[outGain] = 0.0f;
                mBitMangler.setOutputGain(userParams[outGain]);
                break;
            } else {
                userParams[outGain] = newValue;
                mBitMangler.setOutputGain(userParams[outGain]);
                break;
            }
        case shift:
            if(newValue < 0.0f) {
                userParams[shift] = 0.0f;
                mBitMangler.setShift((int) userParams[shift]);
                break;
            } else {
                userParams[shift] = newValue;
                mBitMangler.setShift((int) userParams[shift]);
                break;
            }
        case targetBitDepth:
            userParams[targetBitDepth] = newValue;
            mBitMangler.setTargetBitDepth((int) userParams[targetBitDepth]);
            break;
        case lpFreq:
            if(newValue >= 0.0f && newValue <= 20000.0f) {
                userParams[lpFreq] = newValue;
                mBitMangler.setLPFreq(userParams[lpFreq]);
            }
            break;
        case hpFreq:
            if(newValue >= 0.0f && newValue <= 20000.0f) {
                userParams[hpFreq] = newValue;
                mBitMangler.setHPFreq(userParams[hpFreq]);
            }
            break;
        case lpEnabled:
            if(newValue >= 1.0f) {
                userParams[lpEnabled] = 1.0f;
            } else {
                userParams[lpEnabled] = 0.0f;
                mBitMangler.flushLPBuffers();
            }
            break;
        case hpEnabled:
            if(newValue >= 1.0f) {
                userParams[hpEnabled] = 1.0f;
            } else {
                userParams[hpEnabled] = 0.0f;
                mBitMangler.flushHPBuffers();
            }
            break;
        case drive:
            userParams[drive] = newValue;
            mBitMangler.setDrive(userParams[drive]);
            break;
        case error:
            if(newValue < 0.0f) {
                userParams[error] = 0.0f;
            } else {
                userParams[error] = newValue;
            }
            mBitMangler.setError(userParams[error]);
            break;
        case clip:
            if(newValue > 0.0f) {
                userParams[clip] = 1.0f;
            } else {
                userParams[clip] = 0.0f;
            }
            break;
        default:
            return; //Return before requesting a UI update; we don't need one.
    }
    
    RequestUIUpdate();
}

const String BitManglerAudioProcessor::getParameterName (int index)
{
    switch(index) {
        case bypass:
            return "Bypass";
        case inGain:
            return "Input Gain";
        case outGain:
            return "Output Gain";
        case shift:
            return "Bit Shift";
        case targetBitDepth:
            return "Bit Depth";
        case lpFreq:
            return "Low Pass Freq";
        case hpFreq:
            return "High Pass Freq";
        case lpEnabled:
            return "Low Pass Enabled";
        case hpEnabled:
            return "High Pass Enabled";
        case drive:
            return "Drive";
        case error:
            return "% Error";
        case clip:
            return "Clipping Style";
        default:
            return String::empty;
    }
}

const String BitManglerAudioProcessor::getParameterText (int index)
{
    if(index >= 0 && index < totalNumParams) {
        return String(userParams[index]); //Convert the value of the parameter to a string and return it.
    } else {
        return String::empty;
    }
}

const String BitManglerAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String BitManglerAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool BitManglerAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool BitManglerAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool BitManglerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BitManglerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BitManglerAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double BitManglerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BitManglerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BitManglerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BitManglerAudioProcessor::setCurrentProgram (int index)
{
}

const String BitManglerAudioProcessor::getProgramName (int index)
{
    return String();
}

void BitManglerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void BitManglerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void BitManglerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void BitManglerAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    if(getNumInputChannels() == 2 && !userParams[bypass]) {
        //We're not bypassed and have the correct channel configuration.
        //Let's do something cool to the audio.
        
        float *leftBuffer = buffer.getWritePointer(0);
        float *rightBuffer = buffer.getWritePointer(1);
        long i;
        int j;
        
        //Apply DSP in the following order:
        // 1. Input gain.
        // 2. Introduce error.
        // 3. Bitcrush.
        // 4. Clip/Saturate
        // 5. Filter
        // 6. Output gain.
        for(i = 0; i < buffer.getNumSamples(); ++i) {
            // 1. Input gain.
            mBitMangler.applyInputGain(&leftBuffer[i], &rightBuffer[i]);
            
            //2. Introduce error.
            mBitMangler.applyError(&leftBuffer[i], &rightBuffer[i]);
            
            // 3. Bitcrush.
            //Minor optimization to save a few call
            if(getParameter(targetBitDepth) < 24) {
                mBitMangler.bitCrush(&leftBuffer[i], &rightBuffer[i]);
            }
            
            //4. Clip/Saturate.
            if(getParameter(clip) == 0.0f) {
                mBitMangler.hardClip(&leftBuffer[i], &rightBuffer[i]);
            } else if(getParameter(clip) == 1.0f) {
                mBitMangler.softClip(&leftBuffer[i], &rightBuffer[i]);
            }
            
            // 5. Filter.
            if(getParameter(lpEnabled) == 1.0f) {
                mBitMangler.LPFilter(&leftBuffer[i], &rightBuffer[i], getSampleRate());
            }
            if(getParameter(hpEnabled) == 1.0f) {
                mBitMangler.HPFilter(&leftBuffer[i], &rightBuffer[i], getSampleRate());
            }
            
            // 6. Output gain.
            mBitMangler.applyOutputGain(&leftBuffer[i], &rightBuffer[i]);
        }
    }
}

//==============================================================================
bool BitManglerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* BitManglerAudioProcessor::createEditor()
{
    return new BitManglerAudioProcessorEditor (*this);
}

//==============================================================================
void BitManglerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    /* //I'm gonna try to make this work, because it's pretty useful if done right.
    //Might as well do this the stone-age way (as a block of binary data).
    destData.reset();
    destData.insert(userParams, (size_t) (totalNumParams + 1) * sizeof(float), (size_t) 0); */
    
    //Attempt no. 2, this time using an XML library.
    //Idea sourced from the JUCE demo plugin; original implementation.
    //Hopefully I can create something maintenance-free.
    
    //Create the root XML node/element.
    XmlElement xml("BITMANGLERSETTINGS");
    
    //Set attributes.
    for(int i = 0; i < totalNumParams; ++i) {
        xml.setAttribute(getParameterName(i), getParameter(i));
    }
    
    //Dump to the given memory block.
    copyXmlToBinary(xml, destData);
}

void BitManglerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    
    /* //C-style cast of a data block to a pointer which can then be indexed as an array.
    float* tmpParams = (float*) data;
    
    //Reset all parameters and UI.
    for(int i = 0; i < totalNumParams; ++i) {
        setParameter(i, tmpParams[i]);
    }
    
    RequestUIUpdate(); */
    
    //Attempt no. 2. Code sourced from the JUCE demo plugin with mild modifications.
    
    //Retrieve the XML information
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    
    //Parse it all out.
    if(xmlState != nullptr) {
        //Make sure that we've got the right data.
        if(xmlState->hasTagName("BITMANGLERSETTINGS")) {
            //Pull information and push it to our plugin.
            for(int i = 0; i < totalNumParams; ++i) {
                setParameter(i, (float) xmlState->getDoubleAttribute(getParameterName(i), getParameter(i)));
            }
        }
    }
    
    RequestUIUpdate();
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BitManglerAudioProcessor();
}
