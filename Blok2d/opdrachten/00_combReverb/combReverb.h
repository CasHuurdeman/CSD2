//
// Created by cashu on 13/05/2025.
//

#include "effect.h"
#include "combFilter.h"

#pragma once

class CombReverb : public Effect{
public:
  CombReverb(float DelayTime);
  ~CombReverb();

  double applyEffect(double input) override;

  //snake case because g should not be a capital letter
  //TODO - Does this work?
  void change_g(float &gCurrent, float gNew);

  void prepare(unsigned int samplerate);

private:
  //TODO - Use array
  float g1 = 0.89f;
  float g2 = 0.89f;
  float g3 = 0.89f;
  float g4 = 0.89f;

  //TODO - Use array
  CombFilter CF1{1, g1};
  CombFilter CF2{2, g2};
  CombFilter CF3{3, g3};
  CombFilter CF4{4, g4};

  unsigned int samplerate;
};
