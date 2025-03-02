//
// Created by cashu on 15/02/2025.
//
#include "circularBuffer.h"
#include <iostream>

CircularBuffer::CircularBuffer(int bufferSize, int numSamplesDelay) {
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

int CircularBuffer::getBufferSize(){
  return bufferSize;
}



void CircularBuffer::write(float sample) {
    buffer[writeHead] = sample;
}

float CircularBuffer::read() {
   return buffer[readHead];
}

void CircularBuffer::setDelay() {
    readHead = writeHead - numSamplesDelay;
}

//wrap function is inside incrementHead
void CircularBuffer::incrementHead(int& head){
    if(head >= bufferSize){
        head -= bufferSize;
    }
    else { head += 1; }
}

void CircularBuffer::tick() {
    setDelay();
    incrementHead(writeHead);
    incrementHead(readHead);
}
