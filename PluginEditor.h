/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_8FF9DA2A914278E4__
#define __JUCE_HEADER_8FF9DA2A914278E4__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class BitManglerAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Timer,
                                        public SliderListener,
                                        public ButtonListener,
                                        public ComboBoxListener
{
public:
    //==============================================================================
    BitManglerAudioProcessorEditor (BitManglerAudioProcessor& ownerFilter);
    ~BitManglerAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();

    BitManglerAudioProcessor* getProcessor() const {
        return static_cast <BitManglerAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> inputGainSld;
    ScopedPointer<Slider> outputGainSld;
    ScopedPointer<Slider> ErrorSld;
    ScopedPointer<Slider> bitCrushSld;
    ScopedPointer<Label> errorLabel;
    ScopedPointer<Label> crushLabel;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> label6;
    ScopedPointer<ToggleButton> bypassButton;
    ScopedPointer<Label> label7;
    ScopedPointer<Slider> lpSlider;
    ScopedPointer<Slider> hpSlider;
    ScopedPointer<Label> label8;
    ScopedPointer<Label> label9;
    ScopedPointer<ToggleButton> hpButton;
    ScopedPointer<ToggleButton> lpButton;
    ScopedPointer<Label> label10;
    ScopedPointer<Label> label11;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> label13;
    ScopedPointer<Slider> driveSld;
    ScopedPointer<Label> driveLabel;
    ScopedPointer<Label> label14;
    ScopedPointer<ComboBox> clipBox;
    ScopedPointer<Label> label15;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BitManglerAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_8FF9DA2A914278E4__
