//
// Created by cashu on 02/03/2025.
//
#pragma once

#include <fastSine.h>
#include <square.h>
#include <saw.h>
#include <triangle.h>

class LFO {
//enum before constructor list to use it in the constructor
  enum Waveform {
    sine = 0,
    square,
    saw,
    triangle
  };

public:
  LFO(float rate, float depth, Waveform waveform);
  ~LFO();

private:
  float depth = 1;

};
