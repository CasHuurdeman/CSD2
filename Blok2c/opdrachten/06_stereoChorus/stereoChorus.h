//
// Created by cashu on 22/02/2025.
//
#include "effect.h"
#include "buffer.h"

#ifndef STEREOCHORUS_H
#define STEREOCHORUS_H

class StereoChorus : public Effect{
public:
  StereoChorus();
  ~StereoChorus();

  void applyEffect(const float &input, float &output) override;

private:
  //LFO rate 0 delay - 10 delay bijv.
  //LFODepth --> amount of delay
  //

};


#endif //STEREOCHORUS_H
