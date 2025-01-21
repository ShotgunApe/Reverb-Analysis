#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    roomSize.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    roomSize.setRange (0.0, 127.0, 1.0);
    roomSize.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    roomSize.setPopupDisplayEnabled (true, false, this);
    roomSize.setTextValueSuffix (" Room Size");
    roomSize.setValue(1.0);

    mix.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    mix.setRange (0.0, 127.0, 1.0);
    mix.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    mix.setPopupDisplayEnabled (true, false, this);
    mix.setTextValueSuffix (" Wet/Dry");
    mix.setValue(1.0);

    gain.setSliderStyle (juce::Slider::LinearVertical);
    gain.setRange (0.0, 127.0, 1.0);
    gain.setTextBoxStyle (juce::Slider::NoTextBox, false, 90, 0);
    gain.setPopupDisplayEnabled (true, false, this);
    gain.setTextValueSuffix (" Gain");
    gain.setValue(1.0);
 
    addAndMakeVisible (&roomSize);
    addAndMakeVisible (&mix);
    addAndMakeVisible (&gain);
    addAndMakeVisible (&textLabel);
    addAndMakeVisible (&styleMenu);

    setSize (450, 200);

}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
   // g.drawFittedText ("Hello World again!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    auto area = getLocalBounds();

    roomSize.setBounds (50, 100, 80, 80);
    mix.setBounds (150, 100, 80, 80);
    gain.setBounds (400, 25, 50, 150);
    textLabel.setBounds (10, 10, 300, 10);
    styleMenu.setBounds (50, 30, 350, 25);
}