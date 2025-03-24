//
// Created by cashu on 21/03/2025.
//

#include "RMS.h"
#include <cmath>
#include <iostream>
#include "delayMath.h"

RMS::RMS(float bufferSizeInMs){
  this->bufferSizeInMs = bufferSizeInMs;
}


void RMS::prepare(int samplerate){
  this->samplerate = samplerate;

  bufferSize = DelayMath::msToSamples(bufferSizeInMs, samplerate);

  buffer = new float[bufferSize];
  for (int i = 0; i < bufferSize; i++) {
    buffer[i] = 0;
  }
}

RMS::~RMS(){
  delete [] buffer;
  buffer = nullptr;
}

float RMS::calculateRMS(float input){

//FIXME - there is a bug somewhere
  //This code is practically a for loop working on the samplerate
  // WATCH OUT '>=' needed to not read out of the buffer
    if (bufferCount >= bufferSize) {
      bufferCount = 0;
    }
    //feedback is a variable which stores the square sum of the buffer
    //this works by subtracting the oldest sample of the buffer from the sum and then adding the new one
    //this is much more efficient than calculating the buffer sum in a forloop
    float sqrInput = input * input;
    feedback = feedback - buffer[bufferCount] + sqrInput;
    buffer[bufferCount] = input*input;
    RMSValue = sqrt(feedback/(float)bufferSize);

    bufferCount++;

  return RMSValue;
}

//TODO - validation
void RMS::setBufferSize(float bufferSizeInMs){
  this->bufferSizeInMs = bufferSizeInMs;
  bufferSize = DelayMath::msToSamples(bufferSizeInMs, samplerate);

  if (buffer != nullptr) {
    delete [] buffer;
    buffer = nullptr;
  }

  buffer = new float[bufferSize];
  for (int i = 0; i < bufferSize; i++) {
    buffer[i] = 0;
  }
}

float RMS::getRMS() {
  return RMSValue;
}
