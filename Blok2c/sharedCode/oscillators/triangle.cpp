//
// Created by cashu on 02/03/2025.
//
#include "triangle.h"
#include "math.h"

Triangle::Triangle() : Triangle(0, 0) {}

Triangle::Triangle(float frequency, float samplerate) :
  Oscillator(frequency, samplerate){
}

Triangle::~Triangle() {
}

//TODO - this function could be cleaner
void Triangle::calcNextSample()
{
    sample = 4.0f*fabs(phase - 0.5f) -1.0f;
}