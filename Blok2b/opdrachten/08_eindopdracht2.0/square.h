//
// Created by Ciska Vriezenga on 06/12/2022.
//
#include "oscillator.h"

#ifndef BLOK2B_SQUARE_H
#define BLOK2B_SQUARE_H


class Square : public Oscillator {
public:
  Square();
  Square(float frequency, float samplerate);
  ~Square();

protected:
  void calculate() override;
};

#endif  //BLOK2B_SQUARE_H
