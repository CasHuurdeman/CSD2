//
// Created by cashu on 05/12/2024.
//

#include "synth.h"

Synth::Synth(){}

Synth::~Synth(){}

float Synth::getSample() {
    return sample;
}

float Synth::mtof(float midiPitch){
    return 440.0 * pow (2.0, (midiPitch - 69.0f) / 12.0f);
}

//setting new frequency of the melody
void Synth::updatePitch(Melody& melody, Synth& synth) {
    float note = melody.getNote();
    float freq = mtof (note);
    setFrequency(freq);
}

void Synth::setSynthType(SynthType type){
    std::cout << "\nUsing " << synthTypeToString(type) << " as synthType"
              << std::endl;
}


std::string Synth::synthTypeToString(SynthType type){
    switch(type) {
        case SynthType::OrganSynth:
            return "OrganSynth";
        case SynthType::AdditiveSynth:
            return "AdditiveSynth";
        default:
            return "Invalid synthType";
    }
}
