//
// Created by cashu on 13/05/2025.
//

#include "effect.h"
#include "combFilter.h"
#include "all-passFilter.h"
#include <array>
#include "delayMath.h"
#include "sine.h"

#pragma once

class Reverb : public Effect{
public:
  //TODO - later: RT60, Echo density, Modal density, then an array with N combfilters
  Reverb();
  ~Reverb() override;

  void prepare(unsigned int samplerate);

  double applyEffect(double input) override;

    //TODO (later) - make calculateD and calculate_g
  float calculateD();
  float calculate_g();


private:
  //TODO - Use array --> less readable
 // std::array<CombFilter, 4> CF = {CombFilter{1, g[0]}}

  CombFilter* CF1;
  CombFilter* CF2;
  CombFilter* CF3;
  CombFilter* CF4;

  APF* APF1;
  APF* APF2;

  unsigned int samplerate;
};
