//
// Created by cashu on 06/12/2024.
//
#include "synth.h"
#include "melody.h"
#include "square.h"
#include <array>

#ifndef ORGANSYNTH_H
#define ORGANSYNTH_H

class OrganSynth : public Synth
{
public:
  //constructors
  OrganSynth();
  ~OrganSynth();

  void tick() override;

  void setFrequency(float freq) override;

  Square square1;
  Square square2;


protected:
  void calculate() override;

};

#endif //ORGANSYNTH_H
