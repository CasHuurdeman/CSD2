//
// Created by cashu on 14/02/2025.
//
#include "effect.h"
#include "buffer.h"

#ifndef WAVESHAPER_H
#define WAVESHAPER_H

class WaveShaper : public Effect {
  public:
    WaveShaper(int bufferSize);
    ~WaveShaper();

    void setK(float k);
    void applyEffect(const float &input, float &output) override;
    void billFuffer();

  private:
  float k = -100.0f;
  Buffer buffer;
};


#endif //WAVESHAPER_H
