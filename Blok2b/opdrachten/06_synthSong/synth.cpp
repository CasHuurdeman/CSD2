//
// Created by cashu on 05/12/2024.
//

#include "synth.h"

Synth::Synth(){
  std::cout<<"Synth - constructor"<<std::endl;
}

Synth::~Synth(){
	std::cout<<"Synth - destructor"<<std::endl;
}

float Synth::mtof(float midiPitch){
    return 440.0 * pow (2.0, (midiPitch - 69.0f) / 12.0f);
}

void Synth::updatePitch(Melody &melody, Square &square) {
    float note = melody.getNote();
    double freq = mtof (note);
    std::cout << "next note: " << note << ", has frequency " << freq
              << std::endl;
    square.setFrequency (freq);
}
