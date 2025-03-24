//
// Created by cashu on 21/03/2025.
//
#pragma once

#include "circularBuffer.h"
#include "effect.h"

class RMS {
public:

  RMS() = default;
  RMS(float bufferSizeInMs);
  ~RMS();

  float calculateRMS(float input);
  void prepare(int samplerate);

  float getRMS();
  void setBufferSize(float bufferSizeInMs);

private:
  //samplerate may get overridden by prepare
  int samplerate = 48000;

  float* buffer= nullptr;
  int bufferSize = 0;
  //bufferSize in milliseconds
  float bufferSizeInMs = 0;


  int bufferCount = 0;
  float feedback = 0.0;
  float RMSValue = 0.0;

};
