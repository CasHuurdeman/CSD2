//
// Created by cashu on 06/12/2024.
//

#include "organSynth.h"
#include "square.h"


OrganSynth::OrganSynth() : Synth(){}

OrganSynth::~OrganSynth(){}

void OrganSynth::calculate(){
  sample = (square1.getSample() + square2.getSample()) *0.5;
}

void OrganSynth::tick() {
    calculate();
    square1.tick();
    square2.tick();
}

void OrganSynth::setFrequency(float freq) {
    square1.setFrequency (freq);
    square2.setFrequency (freq*1.51f);
}