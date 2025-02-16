//
// Created by cashu on 14/02/2025.
//
#include "effect.h"

#ifndef WAVESHAPER_H
#define WAVESHAPER_H

class WaveShaper : public Effect {
  public:
    WaveShaper(int bufferSize);
    ~WaveShaper();

    void setK(float k);
    void applyEffect(const float &input, float &output) override;
    void fillBuffer();

  private:
  float k = 1.0f;
  float* buffer;
  int bufferSize;
};


#endif //WAVESHAPER_H
