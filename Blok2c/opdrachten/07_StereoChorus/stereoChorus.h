//
// Created by cashu on 22/02/2025.
//
#pragma once

#include "effect.h"
#include "circularBuffer.h"
#include "LFO.h"

class StereoChorus : public Effect{
public:
  StereoChorus(){};
  ~StereoChorus(){};

  void applyEffect(const float &input, float &output) override;

private:


};
