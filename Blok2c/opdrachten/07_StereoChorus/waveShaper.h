//
// Created by cashu on 14/02/2025.
//
#pragma once

#include "effect.h"
#include "circularBuffer.h"

class WaveShaper : public Effect {
  public:
    WaveShaper(int bufferSize);
    ~WaveShaper();

    void setK(float k);
    void applyEffect(const float &input, float &output) override;
    void billFuffer();

  private:
  float k = 10.0f;
  float* buffer;
  int bufferSize;
};