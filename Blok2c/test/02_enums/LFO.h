//
// Created by cashu on 02/03/2025.
//
#include <fastSine.h>
#include <square.h>
#include <saw.h>
#include <triangle.h>

#ifndef LFO_H
#define LFO_H

class LFO {
public:

  enum Waveform {
    sine = 0,
    square,
    saw,
    triangle
  };

  LFO(float rate, float depth, Waveform waveform);
  ~LFO();


private:

};

#endif //LFO_H
