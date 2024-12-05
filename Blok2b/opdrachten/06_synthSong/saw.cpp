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
    sample =  (2*phase -1) * amplitude; //is dit de mooiste manier?

}