//
// Created by cashu on 05/12/2024.
//
#include "square.h"


Square::Square(float frequency, float samplerate) : Oscillator()
{
    std::cout << "Square - constructor\n";
    this->frequency = frequency;
    this->samplerate = samplerate;
}



Square::~Square() {
    std::cout << "Square - destructor\n";
}

void Square::tick() {
    // NOTE 1. - frequency / SAMPLERATE can be implemented in a more efficient way
    phase += frequency / samplerate;
    if(phase > 1.0f) {
        phase -= 1.0f;
    }
    if(phase < 0.5f){
    sample = -1 * amplitude;
    }
    else {
      sample = amplitude;
    }
}