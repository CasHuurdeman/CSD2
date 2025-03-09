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

  //LFO rate 0 delay - 10 delay bijv.
  //LFODepth --> amount of delay
  //Do I want modDepth in Chorus or in LFO?
  //FIXME - why doesnt this work
  LFO LFO{2.0f, 1.0f, LFO::triangle};
};
