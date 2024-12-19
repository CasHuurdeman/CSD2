#include "callback.h"
#include "melody.h"
#include "square.h"
#include "synth.h"

CustomCallback::CustomCallback(float sampleRate)
    : AudioCallback(sampleRate), sampleRate(sampleRate) {
    std::cout << "Hallo Ciska" << std::endl;
}

CustomCallback::~CustomCallback() {
    delete synth;
    synth = nullptr;
}

void CustomCallback::prepare(int sampleRate) {
    this->sampleRate = sampleRate;
    std::cout << "\nsampleRate: " << sampleRate << "\n";

    synth = new AdditiveSynth();
    synth->fillSines();

    synth->updatePitch(melody, *synth);
}

void CustomCallback::process(AudioBuffer buffer) {
    auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

    for (int sample = 0u; sample < numFrames; ++sample) {
        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            outputChannels[channel][sample] = 0.0f;
            outputChannels[channel][sample] = synth->getSample() * amplitude;
        }
        //tick has to be after the channel loop
        synth->tick();

        /* After every sample, check if we need to advance to the next note
         * This is a bit awkward in this scheme of buffers per channel
         *  In a multichannel setting we should update pitches independently per channel!
         */
        if (frameIndex >= noteDelayFactor * sampleRate) {
            frameIndex = 0;
            synth->updatePitch(melody, *synth);
        } else {
            frameIndex++;
        }
    }
}