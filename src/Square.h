#pragma once
#include <juce_gui_basics/juce_gui_basics.h>

class Square : public Juce::Component {
	public:
		void const(juce::Graphics&) override;
		void resized() override;
};
