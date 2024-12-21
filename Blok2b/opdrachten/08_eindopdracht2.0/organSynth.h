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

  void setFrequency(float freq) override;

protected:
  void calculate() override;
  void tick() override;

  //declaring the functions because otherwise this would be an abstract class
  void fillSines() override{};
  void setNumOfHarmonics(int numHarmonics) override{};

  Square square1;
  Square square2;
};

#endif //ORGANSYNTH_H
