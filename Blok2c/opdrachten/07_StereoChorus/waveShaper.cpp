//
// Created by cashu on 14/02/2025.
//
#include "waveShaper.h"
#include <iostream>
#include <interpolation.h>


WaveShaper::WaveShaper(int bufferSize){
    buffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }

    this->bufferSize = bufferSize;
    billFuffer();
}

WaveShaper::~WaveShaper() {
    delete [] buffer;
    buffer = nullptr;
}

void WaveShaper::applyEffect(const float &input, float &output){

    // map range [-1, 1] to [0, bufferSize - 1]
    float index = (input + 1.0f) * (0.5f * bufferSize);
    // interpolate! index lies in between 2 indices
    int i = (int)index;
    float indexDecimal = index - (float)i;
    output = Interpolation::linMap(indexDecimal, buffer[i], buffer[i + 1]);
}


void WaveShaper::setK(float k) {
    //-20 and 21 are chosen 'randomly'
    //21 instead of 20 because it's funny
    if (k < -20 || k > 21)
    this->k = k;
    billFuffer();
}

//TODO - comments
void WaveShaper::billFuffer() {
    for (int i = 0; i < bufferSize; i++) {
        float input = (float)i/(0.5f * bufferSize) - 1.0f;
        buffer[i] = (1/atan(k)) * atan(k * input); //TODO - bron (prikle)
    }
}
