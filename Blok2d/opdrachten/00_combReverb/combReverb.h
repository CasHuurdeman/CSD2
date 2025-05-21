//
// Created by cashu on 13/05/2025.
//

#include "effect.h"
#include "combFilter.h"
#include <array>
#include "delayMath.h"

#pragma once

class CombReverb : public Effect{
public:
  CombReverb(float DelayTime);
  ~CombReverb();

  double applyEffect(double input) override;

  //snake case because g should not be a capital letter
  //TODO - Does this work? --> this is not the way to change it
  void change_g(float &gCurrent, float gNew);


  void prepare(unsigned int samplerate);

private:
    std::array<float, 4> g = {0.89f, 0.89f, 0.89f, 0.89f};
    std::array<unsigned int, 4> D = {1,2,3,4};

  //TODO - Use array --> less readable
 // std::array<CombFilter, 4> CF = {CombFilter{1, g[0]}}

  CombFilter CF1;
  CombFilter CF2;
  CombFilter CF3;
  CombFilter CF4;

  unsigned int samplerate;
};
