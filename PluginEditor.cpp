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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
BitManglerAudioProcessorEditor::BitManglerAudioProcessorEditor (BitManglerAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (inputGainSld = new Slider ("Input Gain Slider"));
    inputGainSld->setRange (-75, 20, 0.1);
    inputGainSld->setSliderStyle (Slider::LinearVertical);
    inputGainSld->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    inputGainSld->setColour (Slider::thumbColourId, Colours::black);
    inputGainSld->setColour (Slider::trackColourId, Colour (0xdf0ed500));
    inputGainSld->addListener (this);

    addAndMakeVisible (outputGainSld = new Slider ("Output Gain Slider"));
    outputGainSld->setRange (-75, 20, 0.1);
    outputGainSld->setSliderStyle (Slider::LinearVertical);
    outputGainSld->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    outputGainSld->setColour (Slider::thumbColourId, Colours::black);
    outputGainSld->setColour (Slider::trackColourId, Colour (0xdf0ed500));
    outputGainSld->addListener (this);

    addAndMakeVisible (ErrorSld = new Slider ("Error Slider"));
    ErrorSld->setRange (0, 50, 0.1);
    ErrorSld->setSliderStyle (Slider::LinearHorizontal);
    ErrorSld->setTextBoxStyle (Slider::TextBoxRight, false, 40, 20);
    ErrorSld->setColour (Slider::thumbColourId, Colour (0xff0c0c0c));
    ErrorSld->setColour (Slider::trackColourId, Colour (0xdf0ed500));
    ErrorSld->addListener (this);

    addAndMakeVisible (bitCrushSld = new Slider ("Bit Crush Slider"));
    bitCrushSld->setRange (1, 24, 1);
    bitCrushSld->setSliderStyle (Slider::LinearHorizontal);
    bitCrushSld->setTextBoxStyle (Slider::TextBoxRight, false, 40, 20);
    bitCrushSld->setColour (Slider::thumbColourId, Colours::black);
    bitCrushSld->setColour (Slider::trackColourId, Colour (0xdf0ed500));
    bitCrushSld->addListener (this);

    addAndMakeVisible (errorLabel = new Label ("Error Label",
                                               TRANS("% Error")));
    errorLabel->setFont (Font ("KaiTi", 15.00f, Font::plain));
    errorLabel->setJustificationType (Justification::centredLeft);
    errorLabel->setEditable (false, false, false);
    errorLabel->setColour (Label::textColourId, Colours::white);
    errorLabel->setColour (TextEditor::textColourId, Colours::black);
    errorLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (crushLabel = new Label ("Crush Label",
                                               TRANS("Bit Crusher")));
    crushLabel->setFont (Font ("KaiTi", 15.00f, Font::plain));
    crushLabel->setJustificationType (Justification::centredLeft);
    crushLabel->setEditable (false, false, false);
    crushLabel->setColour (Label::textColourId, Colours::white);
    crushLabel->setColour (TextEditor::textColourId, Colours::black);
    crushLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("bits")));
    label2->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Bit Mangler")));
    label3->setFont (Font ("KaiTi", 35.00f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colour (0xff0ed500));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("In")));
    label4->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::white);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Out")));
    label5->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colours::white);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Gain")));
    label6->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colour (0xfffffefe));
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bypassButton = new ToggleButton ("Bypass"));
    bypassButton->setButtonText (String::empty);
    bypassButton->addListener (this);
    bypassButton->setColour (ToggleButton::textColourId, Colours::white);

    addAndMakeVisible (label7 = new Label ("Bypass",
                                           TRANS("Bypass")));
    label7->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colours::white);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lpSlider = new Slider ("Low Pass Slider"));
    lpSlider->setRange (20, 20000, 1);
    lpSlider->setSliderStyle (Slider::LinearVertical);
    lpSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    lpSlider->setColour (Slider::thumbColourId, Colours::black);
    lpSlider->setColour (Slider::trackColourId, Colour (0xdf0ed500));
    lpSlider->addListener (this);

    addAndMakeVisible (hpSlider = new Slider ("High Pass Slider"));
    hpSlider->setRange (10, 18000, 1);
    hpSlider->setSliderStyle (Slider::LinearVertical);
    hpSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 60, 20);
    hpSlider->setColour (Slider::backgroundColourId, Colour (0x00000000));
    hpSlider->setColour (Slider::thumbColourId, Colours::black);
    hpSlider->setColour (Slider::trackColourId, Colour (0xdf0ed500));
    hpSlider->addListener (this);

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("LP Filter")));
    label8->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label8->setJustificationType (Justification::centred);
    label8->setEditable (false, false, false);
    label8->setColour (Label::textColourId, Colours::white);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("HP Filter")));
    label9->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label9->setJustificationType (Justification::centred);
    label9->setEditable (false, false, false);
    label9->setColour (Label::textColourId, Colours::white);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (hpButton = new ToggleButton ("new toggle button"));
    hpButton->setButtonText (String::empty);
    hpButton->addListener (this);

    addAndMakeVisible (lpButton = new ToggleButton ("new toggle button"));
    lpButton->setButtonText (String::empty);
    lpButton->addListener (this);

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("HP Filter Enabled")));
    label10->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colours::white);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label11 = new Label ("new label",
                                            TRANS("LP Filter Enabled")));
    label11->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (Label::textColourId, Colours::white);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label12 = new Label ("new label",
                                            TRANS("Hz")));
    label12->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colours::white);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label13 = new Label ("new label",
                                            TRANS("Hz")));
    label13->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (Label::textColourId, Colours::white);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (driveSld = new Slider ("Drive Slider"));
    driveSld->setRange (-10, 20, 0.1);
    driveSld->setSliderStyle (Slider::LinearHorizontal);
    driveSld->setTextBoxStyle (Slider::TextBoxRight, false, 40, 20);
    driveSld->setColour (Slider::thumbColourId, Colours::black);
    driveSld->setColour (Slider::trackColourId, Colour (0xdf0ed500));
    driveSld->addListener (this);

    addAndMakeVisible (driveLabel = new Label ("Drive Label",
                                               TRANS("Drive")));
    driveLabel->setFont (Font ("KaiTi", 15.00f, Font::plain));
    driveLabel->setJustificationType (Justification::centredLeft);
    driveLabel->setEditable (false, false, false);
    driveLabel->setColour (Label::textColourId, Colours::white);
    driveLabel->setColour (TextEditor::textColourId, Colours::black);
    driveLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label14 = new Label ("new label",
                                            TRANS("dB")));
    label14->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (Label::textColourId, Colours::white);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (clipBox = new ComboBox ("Clipping Style Box"));
    clipBox->setEditableText (false);
    clipBox->setJustificationType (Justification::centredLeft);
    clipBox->setTextWhenNothingSelected (String::empty);
    clipBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    clipBox->addItem (TRANS("Hard Clip"), 1);
    clipBox->addItem (TRANS("Soft Clip"), 2);
    clipBox->addListener (this);

    addAndMakeVisible (label15 = new Label ("new label",
                                            TRANS("Clipping Style")));
    label15->setFont (Font ("KaiTi", 15.00f, Font::plain));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (Label::textColourId, Colours::white);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (604, 348);


    //[Constructor] You can add your own custom stuff here..
    startTimer(30); //We'll experiment with a short interval this time.

    //Set double-click return values
    inputGainSld->setDoubleClickReturnValue(true, 0.0f);
    outputGainSld->setDoubleClickReturnValue(true, 0.0f);

    //Force a parameter reset upon re-opening.
    ownerFilter.RequestUIUpdate();
    timerCallback();
    //[/Constructor]
}

BitManglerAudioProcessorEditor::~BitManglerAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    inputGainSld = nullptr;
    outputGainSld = nullptr;
    ErrorSld = nullptr;
    bitCrushSld = nullptr;
    errorLabel = nullptr;
    crushLabel = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    bypassButton = nullptr;
    label7 = nullptr;
    lpSlider = nullptr;
    hpSlider = nullptr;
    label8 = nullptr;
    label9 = nullptr;
    hpButton = nullptr;
    lpButton = nullptr;
    label10 = nullptr;
    label11 = nullptr;
    label12 = nullptr;
    label13 = nullptr;
    driveSld = nullptr;
    driveLabel = nullptr;
    label14 = nullptr;
    clipBox = nullptr;
    label15 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void BitManglerAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void BitManglerAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    inputGainSld->setBounds (16, 16, 48, 240);
    outputGainSld->setBounds (72, 16, 48, 240);
    ErrorSld->setBounds (128, 104, 248, 24);
    bitCrushSld->setBounds (128, 152, 248, 24);
    errorLabel->setBounds (144, 80, 150, 24);
    crushLabel->setBounds (144, 128, 150, 24);
    label2->setBounds (376, 152, 40, 24);
    label3->setBounds (160, 16, 224, 48);
    label4->setBounds (24, 256, 32, 24);
    label5->setBounds (72, 256, 47, 24);
    label6->setBounds (24, 272, 88, 24);
    bypassButton->setBounds (24, 304, 24, 24);
    label7->setBounds (48, 304, 55, 24);
    lpSlider->setBounds (496, 16, 80, 240);
    hpSlider->setBounds (408, 16, 80, 240);
    label8->setBounds (496, 256, 80, 24);
    label9->setBounds (408, 256, 80, 24);
    hpButton->setBounds (408, 288, 23, 24);
    lpButton->setBounds (408, 312, 23, 24);
    label10->setBounds (432, 288, 150, 24);
    label11->setBounds (432, 312, 150, 24);
    label12->setBounds (480, 232, 32, 24);
    label13->setBounds (568, 232, 32, 24);
    driveSld->setBounds (128, 200, 248, 24);
    driveLabel->setBounds (144, 176, 150, 24);
    label14->setBounds (376, 200, 40, 24);
    clipBox->setBounds (256, 272, 126, 24);
    label15->setBounds (136, 272, 120, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void BitManglerAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    BitManglerAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == inputGainSld)
    {
        //[UserSliderCode_inputGainSld] -- add your slider handling code here..

        //Push the value of the input gain slider to the audio processor.
        ourProcessor->setParameter(BitManglerAudioProcessor::inGain, (float) sqrt(pow(10, .1*inputGainSld->getValue())));
        //[/UserSliderCode_inputGainSld]
    }
    else if (sliderThatWasMoved == outputGainSld)
    {
        //[UserSliderCode_outputGainSld] -- add your slider handling code here..

        //Push the value of the input gain slider to the audio processor.
        ourProcessor->setParameter(BitManglerAudioProcessor::outGain, (float) sqrt(pow(10, .1*outputGainSld->getValue())));
        //[/UserSliderCode_outputGainSld]
    }
    else if (sliderThatWasMoved == ErrorSld)
    {
        //[UserSliderCode_ErrorSld] -- add your slider handling code here..
        ourProcessor->setParameter(BitManglerAudioProcessor::error, ErrorSld->getValue()/100.0f);
        //[/UserSliderCode_ErrorSld]
    }
    else if (sliderThatWasMoved == bitCrushSld)
    {
        //[UserSliderCode_bitCrushSld] -- add your slider handling code here..

        //Push the value of the bit crush slider to the audio processor
        ourProcessor->setParameter(BitManglerAudioProcessor::targetBitDepth, (float) bitCrushSld->getValue());
        //[/UserSliderCode_bitCrushSld]
    }
    else if (sliderThatWasMoved == lpSlider)
    {
        //[UserSliderCode_lpSlider] -- add your slider handling code here..
        ourProcessor->setParameter(BitManglerAudioProcessor::lpFreq, (float) lpSlider->getValue());
        //[/UserSliderCode_lpSlider]
    }
    else if (sliderThatWasMoved == hpSlider)
    {
        //[UserSliderCode_hpSlider] -- add your slider handling code here..
        ourProcessor->setParameter(BitManglerAudioProcessor::hpFreq, (float) hpSlider->getValue());
        //[/UserSliderCode_hpSlider]
    }
    else if (sliderThatWasMoved == driveSld)
    {
        //[UserSliderCode_driveSld] -- add your slider handling code here..
        ourProcessor->setParameter(BitManglerAudioProcessor::drive, (float) sqrt(pow(10, .1*driveSld->getValue())));
        //[/UserSliderCode_driveSld]
    }

    //[UsersliderValueChanged_Post]
    ourProcessor = nullptr;
    //[/UsersliderValueChanged_Post]
}

void BitManglerAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    BitManglerAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == bypassButton)
    {
        //[UserButtonCode_bypassButton] -- add your button handler code here..

        //Push the state of the bypass button to the audio processor.
        ourProcessor->setParameter(BitManglerAudioProcessor::bypass, (float) bypassButton->getToggleState());
        //[/UserButtonCode_bypassButton]
    }
    else if (buttonThatWasClicked == hpButton)
    {
        //[UserButtonCode_hpButton] -- add your button handler code here..
        ourProcessor->setParameter(BitManglerAudioProcessor::hpEnabled, (float) hpButton->getToggleState());
        //[/UserButtonCode_hpButton]
    }
    else if (buttonThatWasClicked == lpButton)
    {
        //[UserButtonCode_lpButton] -- add your button handler code here..
        ourProcessor->setParameter(BitManglerAudioProcessor::lpEnabled, (float) lpButton->getToggleState());
        //[/UserButtonCode_lpButton]
    }

    //[UserbuttonClicked_Post]
    ourProcessor = nullptr;
    //[/UserbuttonClicked_Post]
}

void BitManglerAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    BitManglerAudioProcessor* ourProcessor = getProcessor();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == clipBox)
    {
        //[UserComboBoxCode_clipBox] -- add your combo box handling code here..
        ourProcessor->setParameter(BitManglerAudioProcessor::clip, (float) clipBox->getSelectedItemIndex());
        //[/UserComboBoxCode_clipBox]
    }

    //[UsercomboBoxChanged_Post]
    ourProcessor = nullptr;
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void BitManglerAudioProcessorEditor::timerCallback() {
	BitManglerAudioProcessor* ourProcessor = getProcessor();

    //Exchange data between GUI and ourProcessor here.
    if(ourProcessor->NeedsUIUpdate()) {

        //Update bypassButton
        bypassButton->setToggleState(1.0f == ourProcessor->getParameter(BitManglerAudioProcessor::bypass), dontSendNotification);

        //Update inputGainSld
        inputGainSld->setValue(10 * log10((float) pow(ourProcessor->getParameter(BitManglerAudioProcessor::inGain), 2)), dontSendNotification);

        //Update outputGainSld
        outputGainSld->setValue(10 * log10((float) pow(ourProcessor->getParameter(BitManglerAudioProcessor::outGain), 2)), dontSendNotification);

        //Update bitShiftSld
        //bitShiftSld->setValue(ourProcessor->getParameter(BitManglerAudioProcessor::shift), dontSendNotification);

        //Update bitCrushSld
        bitCrushSld->setValue(ourProcessor->getParameter(BitManglerAudioProcessor::targetBitDepth), dontSendNotification);

        //Update hpSlider
        hpSlider->setValue((int) ourProcessor->getParameter(BitManglerAudioProcessor::hpFreq), dontSendNotification);

        //Update lpSlider
        lpSlider->setValue((int) ourProcessor->getParameter(BitManglerAudioProcessor::lpFreq), dontSendNotification);

        //Update hpButton
        hpButton->setToggleState(1.0f == ourProcessor->getParameter(BitManglerAudioProcessor::hpEnabled), dontSendNotification);

        //Update lpButton
        lpButton->setToggleState(1.0f == ourProcessor->getParameter(BitManglerAudioProcessor::lpEnabled), dontSendNotification);

        //Update driveSld
        driveSld->setValue(10 * log10((float) pow(ourProcessor->getParameter(BitManglerAudioProcessor::drive), 2)), dontSendNotification);

        //Update ErrorSld
        ErrorSld->setValue(ourProcessor->getParameter(BitManglerAudioProcessor::error) * 100.0f, dontSendNotification);

        //Update clipBox
        clipBox->setSelectedItemIndex(ourProcessor->getParameter(BitManglerAudioProcessor::clip), dontSendNotification);

        //Clear UI Update flag
        ourProcessor->ClearUIUpdateFlag();
    }

    ourProcessor = nullptr;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="BitManglerAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="BitManglerAudioProcessor&amp; ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="604" initialHeight="348">
  <BACKGROUND backgroundColour="ff000000"/>
  <SLIDER name="Input Gain Slider" id="a311a46bf5d29a78" memberName="inputGainSld"
          virtualName="" explicitFocusOrder="0" pos="16 16 48 240" thumbcol="ff000000"
          trackcol="df0ed500" min="-75" max="20" int="0.10000000000000001"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Output Gain Slider" id="72d0956117bc8903" memberName="outputGainSld"
          virtualName="" explicitFocusOrder="0" pos="72 16 48 240" thumbcol="ff000000"
          trackcol="df0ed500" min="-75" max="20" int="0.10000000000000001"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Error Slider" id="565fc32d28e6b24f" memberName="ErrorSld"
          virtualName="" explicitFocusOrder="0" pos="128 104 248 24" thumbcol="ff0c0c0c"
          trackcol="df0ed500" min="0" max="50" int="0.10000000000000001"
          style="LinearHorizontal" textBoxPos="TextBoxRight" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Bit Crush Slider" id="625d5c81bfcf3e1b" memberName="bitCrushSld"
          virtualName="" explicitFocusOrder="0" pos="128 152 248 24" thumbcol="ff000000"
          trackcol="df0ed500" min="1" max="24" int="1" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="40"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Error Label" id="e850ac0f94cc1377" memberName="errorLabel"
         virtualName="" explicitFocusOrder="0" pos="144 80 150 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="% Error" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="Crush Label" id="511c6c9727e43675" memberName="crushLabel"
         virtualName="" explicitFocusOrder="0" pos="144 128 150 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Bit Crusher" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d859fd856cecffab" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="376 152 40 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="bits" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="be270b33afeb27ed" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="160 16 224 48" textCol="ff0ed500"
         edTextCol="ff000000" edBkgCol="0" labelText="Bit Mangler" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="35" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="56a6de5e1fcbe078" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="24 256 32 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="In" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="32f20900f8c8ed1b" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="72 256 47 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Out" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="97ed6e7dc8dd31ce" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="24 272 88 24" textCol="fffffefe"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="Bypass" id="3494a0645f3bd60e" memberName="bypassButton"
                virtualName="" explicitFocusOrder="0" pos="24 304 24 24" txtcol="ffffffff"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <LABEL name="Bypass" id="2e110bb0770cafef" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="48 304 55 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Bypass" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="Low Pass Slider" id="262faf51eef0b12c" memberName="lpSlider"
          virtualName="" explicitFocusOrder="0" pos="496 16 80 240" thumbcol="ff000000"
          trackcol="df0ed500" min="20" max="20000" int="1" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="High Pass Slider" id="22579af5e1cb1a83" memberName="hpSlider"
          virtualName="" explicitFocusOrder="0" pos="408 16 80 240" bkgcol="0"
          thumbcol="ff000000" trackcol="df0ed500" min="10" max="18000"
          int="1" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="27d75334e3119bae" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="496 256 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="LP Filter" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="c95d3cbe6b9e10cf" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="408 256 80 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="HP Filter" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="d75d809885f433a3" memberName="hpButton"
                virtualName="" explicitFocusOrder="0" pos="408 288 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="4eeddea4a5c5cf58" memberName="lpButton"
                virtualName="" explicitFocusOrder="0" pos="408 312 23 24" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="929abb941307fcbc" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="432 288 150 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="HP Filter Enabled"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="KaiTi" fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a7b155470ac9de31" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="432 312 150 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="LP Filter Enabled"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="KaiTi" fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="9b5176af5aeb322b" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="480 232 32 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Hz" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b9010f75a1cf8f27" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="568 232 32 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Hz" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="Drive Slider" id="16c24b2e401c671" memberName="driveSld"
          virtualName="" explicitFocusOrder="0" pos="128 200 248 24" thumbcol="ff000000"
          trackcol="df0ed500" min="-10" max="20" int="0.10000000000000001"
          style="LinearHorizontal" textBoxPos="TextBoxRight" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Drive Label" id="95175d949c3b593d" memberName="driveLabel"
         virtualName="" explicitFocusOrder="0" pos="144 176 150 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Drive" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="80727f66552e0903" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="376 200 40 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="dB" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="KaiTi"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="Clipping Style Box" id="6fd8ab01246572e9" memberName="clipBox"
            virtualName="" explicitFocusOrder="0" pos="256 272 126 24" editable="0"
            layout="33" items="Hard Clip&#10;Soft Clip" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="dd2d4e515ac4f44f" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="136 272 120 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Clipping Style"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="KaiTi" fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
