#include "PluginProcessor.h"
#include "PluginEditor.h"
// #include "Square.h"

AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);

	// addAndMakeVisible(square);
    setSize (850, 600);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(26, 26, 30));

    g.setColour (juce::Colour(214, 222, 223));
    g.setFont (15.0f);
    g.drawFittedText ("Hello!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized()
{
	// put shit on screen
	// square.setBounds(100, 100, 200, 200);

}
