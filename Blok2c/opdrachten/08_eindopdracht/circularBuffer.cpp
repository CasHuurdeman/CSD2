//
// Created by cashu on 15/02/2025.
//
#include "circularBuffer.h"
#include <iostream>

CircularBuffer::CircularBuffer(int bufferSize, float numSamplesDelay) {
    buffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
    this->numSamplesDelay = numSamplesDelay;
}

CircularBuffer::~CircularBuffer(){
    delete [] buffer;
    buffer = nullptr;
}


void CircularBuffer::setBufferSize(int bufferSize){
    this->bufferSize = bufferSize;

    if (buffer != nullptr) {
        delete [] buffer;
        buffer = nullptr;
    }

    buffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

int CircularBuffer::getBufferSize(){return bufferSize;}

int CircularBuffer::getNumSamplesDelay() {return numSamplesDelay;}


void CircularBuffer::setNumSamplesDelay(float numSamplesDelay) {
    if (numSamplesDelay < 0) {
        std::cout << "CircularBuffer::setNumSamplesDelay - numSamplesDelay exceeds range [0, inf]"  << numSamplesDelay << std::endl;
    }else {
        this-> numSamplesDelay = numSamplesDelay;
        updateDelay();
    }
}



void CircularBuffer::write(float sample) {
    buffer[writeHead] = sample;
    wrap(++writeHead);
}

float CircularBuffer::read() {
    const auto output = buffer[readHead];
    readHead++;
    wrap(readHead);
    return output;
}

void CircularBuffer::updateDelay() {
    readHead = writeHead - (int)numSamplesDelay + bufferSize;
    //readHead gets changed--> so wrap
    wrap(readHead);
}


void CircularBuffer::wrap(int &head) {
    if(head >= bufferSize) {
        head -= bufferSize;
    }
}
