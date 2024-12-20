//
// Created by cashu on 05/12/2024.
//
#include "saw.h"
#include "math.h"


Saw::Saw(float frequency, float sampleRate) : Oscillator()
{
    this->frequency = frequency;
    this->sampleRate = sampleRate;
}



Saw::~Saw() {
    std::cout << "Saw - destructor\n";
}

void Saw::calculate() {
    sample =  (2*phase -1) * amplitude;
}