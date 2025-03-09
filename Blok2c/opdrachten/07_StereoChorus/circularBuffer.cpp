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

// FIXME - readHead and writeHead now increase as you 'get' them
int CircularBuffer::getReadHead() {return readHead++;}

int CircularBuffer::getWriteHead() {return writeHead++;}


void CircularBuffer::setNumSamplesDelay(float numSamplesDelay) {
    if (numSamplesDelay < 0) {
        throw "CircularBuffer::setNumSamplesDelay - numSamplesDelay exceeds range [0, inf]";
    }
    this-> numSamplesDelay = numSamplesDelay;
}



void CircularBuffer::write(float sample) {
    buffer[writeHead] = sample;
}

float CircularBuffer::read() {
   return buffer[readHead];
}

void CircularBuffer::setDelay() {
    readHead = writeHead - (int)numSamplesDelay;
}

//TODO - duplicate code
//wrap function is inside incrementHead
void CircularBuffer::wrapRH(){
    if(readHead >= bufferSize){
        readHead -= bufferSize;
    }
}

void CircularBuffer::wrapWH() {
    if(writeHead >= bufferSize){
        writeHead -= bufferSize;
    }
}



// void CircularBuffer::tick() {
//     setDelay();
//     incrementHead(writeHead);
//     incrementHead(readHead);
// }
