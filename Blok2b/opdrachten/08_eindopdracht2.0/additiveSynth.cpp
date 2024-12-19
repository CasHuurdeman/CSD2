//
// Created by cashu on 15/12/2024.
//
#include "additiveSynth.h"

#include <array>
#include <iostream>

AdditiveSynth::AdditiveSynth() : Synth(){
      std::cout << "AdditiveSynth - constructor" << std::endl;
}

AdditiveSynth::~AdditiveSynth(){
     std::cout << "AdditiveSynth - destructor" << std::endl;
}

//Amp is in user settings
void AdditiveSynth::calculate(){
    sample = 0;
    for (int i = 0; i < sines.size(); i++) {
        sample += sines[i].getSample() /sines.size();
    }
}

void AdditiveSynth::tick() {
    calculate();
    for (int i = 0; i < sines.size(); i++) {
        sines[i].tick();
    }
}

void AdditiveSynth::printArray() {
    std::cout << "array: " << std::endl;
    for (int i = 0; i < sines.size(); i++) {
        std::cout << i << std::endl;
    }
}

void AdditiveSynth::setFrequency(float frequency) {
    for (int i = 0; i < sines.size(); i++) {
        sines[i].setFrequency(frequency * (i+1));
    };
    // std::cout << "Sines0: " << sines[0].getFrequency() << std::endl;
    // std::cout << "Sines1: " << sines[1].getFrequency() << std::endl;
}

void AdditiveSynth::fillSines() {
    Sine sine;
    for (int i = 0; i < numOfHarmonics; i++) {
        sines.push_back(sine); ;
        std::cout << i << std::endl;
    }
}