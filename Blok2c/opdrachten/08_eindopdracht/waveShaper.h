//
// Created by cashu on 14/02/2025.
//
#pragma once

#include "effect.h"
#include "RMS.h"

class WaveShaper : public Effect {
  public:
    WaveShaper(int bufferSize);
    ~WaveShaper();

    void setK(float k);
    void applyEffect(const float &input, float &output) override;
    void fillBuffer();

  private:
  //k is just a standard parameter value in mathematics
  float k = 2.0f;
  float* buffer;
  int bufferSize;
};