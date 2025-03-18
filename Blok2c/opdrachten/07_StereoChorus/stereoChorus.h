//
// Created by cashu on 22/02/2025.
//
#pragma once

#include "effect.h"
#include "circularBuffer.h"
#include "chorus.h"

class StereoChorus : public Effect{
public:
  StereoChorus(float rate, float depth, float feedback);
  ~StereoChorus();

  void applyEffect(const float &input, float &output) override;

private:
  float rate;
  float depth;
  float feedback;

  Chorus chorusL;
  Chorus chorusC;
  Chorus chorusR;

};
