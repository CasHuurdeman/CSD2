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

void Saw::tick() {
    // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
    phase += frequency / samplerate;
    if(phase > 1.0f) {
        phase -= 1.0f;
    }
    sample =  (2*phase -1) * amplitude; //is dit de mooiste manier?

}