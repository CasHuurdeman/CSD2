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

void AdditiveSynth::calculate(){
    for (int i = 0; i < sines.size(); i++) {
        sample = sines[i].getFrequency();
    }
    std::cout << sample << std::endl;
}

void AdditiveSynth::tick() {
    calculate();
    for (int i = 0; i < sines.size(); i++) {
        sines[i].tick();
    };
}

void AdditiveSynth::printArray() {
    std::cout << "array: " << std::endl;
    for (int i = 0; i < sines.size(); i++) {
        std::cout << i << std::endl;
    }
}

void AdditiveSynth::setFrequency(float frequency) {
    for (int i = 0; i < sines.size(); i++) {
        sines[i].setFrequency(frequency * i);
    };
}