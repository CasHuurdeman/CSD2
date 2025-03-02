//
// Created by cashu on 02/03/2025.
//
#include "triangle.h"
#include "math.h"

Triangle::Triangle() : Triangle(0, 0) {}

Triangle::Triangle(float frequency, float samplerate) :
  Oscillator(frequency, samplerate)
{
    std::cout << "Triangle - constructor\n";
}

Triangle::~Triangle() {
    std::cout << "Triangle - destructor\n";
}

//TODO - this function could be cleaner
void Triangle::calcNextSample()
{
    // Triangle functionality comes here
    if(phase < 0.25) {
        sample *= 4.0f;
    }
    else if (phase < 0.75){
          sample = sample * -4.0f + 2.0f;
    }
    else sample = sample * 4.0f - 4.0f;
}