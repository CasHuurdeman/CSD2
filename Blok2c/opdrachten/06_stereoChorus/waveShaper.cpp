//
// Created by cashu on 14/02/2025.
//
#include "waveShaper.h"
#include <iostream>
#include <interpolation.h>

//FIXME - this whole effect definitely doesnt work like this, 05_waveShaper does work

WaveShaper::WaveShaper(int bufferSize){
//    buffer = new float[bufferSize];
//    for (int i = 0; i < bufferSize; i++) {
//        buffer[i] = 0;
//    }
//
    // this->bufferSize = bufferSize;

    buffer.setBufferSize(bufferSize);
    billFuffer();
}

WaveShaper::~WaveShaper() {
//    delete [] buffer; //TODO - look into brackets []
//    buffer = nullptr;
}

void WaveShaper::applyEffect(const float &input, float &output){

    // map range [-1, 1] to [0, bufferSize - 1]
    float index = (input + 1.0f) * (0.5f * buffer.getBufferSize());
    // interpolate! index lies in between 2 indices
    int i = (int)index;
    float indexDecimal = index - (float)i;
    output = Interpolation::linMap(indexDecimal, buffer.buffer[i], buffer.buffer[i + 1]);
}

//TODO - add validation,
//maybe comment parameter k
void WaveShaper::setK(float k) {
    this->k = k;
    billFuffer();
}

//TODO - comments
void WaveShaper::billFuffer() {
    for (int i = 0; i < buffer.getBufferSize(); i++) {
        float input = (float)i/(0.5f * buffer.getBufferSize()) - 1.0f;
        buffer.buffer[i] = (1/atan(k)) * atan(k * input); //TODO - bron (prikle)
    }
}
