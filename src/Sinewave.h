// simple test, cba to split into .h and .cpp knowing itll be scrapped
// add to cmake and other shiet btw

#ifndef SINEWAVE_H
#define SINEWAVE_H

#include <juce_audio_basics/juce_audio_basics.h>

class Sinewave {
	public: 
		// init
		void prepare(double sampleRate, int numChannels) {
			currSampleRate = sampleRate;
			timeInc = 1.0f/currSampleRate;
			currTime.resize(numChannels, 0.0f);
		}

		void process(juce::AudioBuffer<float>& buf) {
			if (currTime.size() != buf.getNumChannels()) { return; }

			for (int channel = 0; channel < buf.getNumChannels(); ++channel) {

				// write pointer
				auto* output = buf.getWritePointer(channel);

				for (int sample = 0; sample < buf.getNumSamples(); ++sample) {
					// sin eq
					// need n number of channels for each channel being processed
					output[sample] = amplitude * std::sinf(juce::MathConstants<float>::twoPi * freq * currTime[channel]);
					currTime[channel] = currTime[channel] + timeInc;

				}
			}
		}

	private: 
		// basic sine eq vars
		float amplitude = 0.2f;
		float freq = 311.13f; // middle Eb lol
		float currSampleRate = 0.0f;
		float timeInc = 0.0f;
		std::vector<float> currTime;
};

#endif
