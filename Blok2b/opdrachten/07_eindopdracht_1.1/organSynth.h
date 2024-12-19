//
// Created by cashu on 06/12/2024.
//
#include "synth.h"
#include "melody.h"

#ifndef ORGANSYNTH_H
#define ORGANSYNTH_H

class OrganSynth : public Synth
{
public:
  //constructors
  OrganSynth();
  ~OrganSynth();

  void tick() override;

  void doTheThing(float freq) override{
    square1.setFrequency (freq);
    square2.setFrequency (freq*1.51f);
  }

  Square square1;
  Square square2;

protected:
  void calculate() override;

};

#endif //ORGANSYNTH_H
