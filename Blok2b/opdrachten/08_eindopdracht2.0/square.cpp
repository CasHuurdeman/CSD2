//
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "square.h"

Square::Square() : Oscillator (){}

Square::Square(float frequency, float samplerate) : Oscillator (frequency, samplerate){}

Square::~Square () {}

void Square::calculate() {
  sample = amplitude;
  if (phase >= 0.5) {
    sample *= -1.0f;
  }
}