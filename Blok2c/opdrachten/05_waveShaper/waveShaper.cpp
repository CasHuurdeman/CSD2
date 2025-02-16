//
// Created by cashu on 14/02/2025.
//
#include "waveShaper.h"
#include <iostream>


WaveShaper::WaveShaper(int bufferSize){
    buffer = new float(bufferSize);
    this->bufferSize = bufferSize;
}

WaveShaper::~WaveShaper(){
    delete buffer;
    buffer = nullptr;
}

void WaveShaper::applyEffect(const float &input, float &output){

    output = 1/atan(k) * atan(k * input);

}

void WaveShaper::setK(float k) {
    this->k = k;
}

void WaveShaper::fillBuffer() {

}