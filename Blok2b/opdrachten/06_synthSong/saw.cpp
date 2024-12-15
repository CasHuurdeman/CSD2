//
// Created by cashu on 05/12/2024.
//
#include "saw.h"
#include "math.h"


Saw::Saw(float frequency, float samplerate) : Oscillator()
{
    std::cout << "Saw - constructor\n";
    this->frequency = frequency;
    this->samplerate = samplerate;
}



Saw::~Saw() {
    std::cout << "Saw - destructor\n";
}

void Saw::calculate() {
    // if (sample < 0.25f) {
    //     sample = (4*phase) * amplitude;
    // }
    // else if (sample < 0.75f ) {
    //     sample = (2 + -4*phase) * amplitude;
    // }
    // else {
    //     sample = (-4 + 4*phase) * amplitude;
    // } //triangle??

    sample =  (2.0f * phase -1.0f) * amplitude;

}