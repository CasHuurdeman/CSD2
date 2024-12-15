#include "audiocomponent.h"
//  Daan Schrier
#include "saw.h"
#include "square.h"
#include "sine.h"
#include "melody.h"
#include "synth.h"

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
                outputChannels[channel][sample] = square.getSample();
                square.tick();

                if (frameIndex >= noteDelayFactor * sampleRate) {
                    frameIndex = 0;
                    updatePitch (melody, square);
                }
                else {
                    frameIndex++;
                }
            }
        }
    }

private:
    double sampleRate;
    Square square;
    double amplitude = 0.25;
    Melody melody;
    int frameIndex = 0;

    /* instead of using bpm and specifying note lenghts we'll make every note
     * equal length and specify the delay between notes in terms of the samplerate
     *
     * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be played
     */
    double noteDelayFactor = 0.1;
};