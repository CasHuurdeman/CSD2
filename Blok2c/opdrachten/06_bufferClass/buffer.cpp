//
// Created by cashu on 15/02/2025.
//
#include "buffer.h"
#include <iostream>

Buffer::Buffer(int bufferSize){
    buffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = 0;
    }
}

Buffer::~Buffer(){
    delete [] buffer;
    buffer = nullptr;
}


void Buffer::setBufferSize(int bufferSize){
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

int Buffer::getBufferSize(){
  return bufferSize;
}