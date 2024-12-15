//
// Created by cashu on 06/12/2024.
//
#include "synth.h"

#ifndef ORGANSYNTH_H
#define ORGANSYNTH_H

class OrganSynth : public Synth
{
public:
  //constructors
  OrganSynth();
  ~OrganSynth();

  //methods
  void organ(float frequency);

  //fields

};

#endif //ORGANSYNTH_H
