#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

class DelayLine
{
public:
    DelayLine();
    ~DelayLine();

    void fillBuffer (juce::AudioBuffer<float>& buffer, int channel);
    void readFromBuffer (juce::AudioBuffer<float>& buffer, juce::AudioBuffer<float>& delayBuffer, int channel);
    void updateBufferPosition (juce::AudioBuffer<float>& buffer, juce::AudioBuffer<float>& delayBuffer);
    void setDelay (int time);
    
    juce::AudioBuffer<float>& getBuffer ();

private:
    // For circular array data structure
    juce::AudioBuffer<float> delayBuffer; 
    int writePosition { 0 };
    int delayTime;
};