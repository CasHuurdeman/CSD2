#include "audiocomponent.h"
//  Daan Schrier
#include "sine.h"
#include "square.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback (double Fs) : AudioCallback(Fs) {

    }

    ~CustomCallback() override {

    }

    void prepare (int sampleRate) override {

    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                // write sample to buffer at channel 0, amp = 0.25
                outputChannels[channel][sample] = sine.getSample() * sine2.getSample();
                sine.tick(); sine2.tick();
            }
        }
    }

private:
    Sine sine{440};
    Sine sine2{1};
};