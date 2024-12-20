#include "callback.h"
#include "melody.h"
#include "square.h"
#include "synth.h"
#include "UIUtilities.h"

CustomCallback::CustomCallback(float sampleRate)
    : AudioCallback(sampleRate), sampleRate(sampleRate) {
    std::cout << "Hallo Daan & Ciska" << std::endl;
}

CustomCallback::~CustomCallback() {
    delete synth;
    synth = nullptr;
}

void CustomCallback::prepare(int sampleRate) {
    this->sampleRate = sampleRate;

//-----UI-----------
    //if not created here, out of scope on line 45
    int value = 0;

    // create a string array with the synth type options
    std::string* synthTypeOptions = new std::string[Synth::SynthType::Size];
    for(int i = 0; i < Synth::SynthType::Size; i++) {
        synthTypeOptions[i] = Synth::synthTypeToString((Synth::SynthType)i);
    }

    // retrieve the user selection in form of an enum
    Synth::SynthType synthType = (Synth::SynthType)
      UIUtilities::retrieveSelectionIndex(synthTypeOptions, Synth::SynthType::Size);

    //Retrieve number of
    if (synthType == 1) {
        std::cout << "\nSelect number of harmonics, " << std::endl;
        value =  UIUtilities::retrieveValueInRange(1, 50);
    }

//------END UI-------

    if (synthType == 1) {
        synth = new AdditiveSynth();
        synth->setNumOfHarmonics(value);
        synth->fillSines();
    }
    else {
        synth = new OrganSynth();
    }


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