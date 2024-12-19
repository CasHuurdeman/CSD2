//
// Created by cashu on 06/12/2024.
//

#include "organSynth.h"
#include "square.h"


OrganSynth::OrganSynth() : Synth(){
 std::cout << "OrganSynth - constructor" << std::endl;
}

OrganSynth::~OrganSynth(){
  std::cout << "OrganSynth - destructor" << std::endl;
}

void OrganSynth::calculate(){
  sample = square1.getSample() + square2.getSample();
}

void OrganSynth::tick() {
    calculate();
    square1.tick();
    square2.tick();
}