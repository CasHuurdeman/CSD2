//
// Created by cashu on 15/02/2025.
//
#include "circularBuffer.h"

CircularBuffer::CircularBuffer(int bufferSize){
    buffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

CircularBuffer::~CircularBuffer(){
    delete [] buffer;
    buffer = nullptr;
}

void CircularBuffer::setBufferSize(int bufferSize){
  this->bufferSize = bufferSize;
}

int CircularBuffer::getBufferSize(){
  return bufferSize;
}
