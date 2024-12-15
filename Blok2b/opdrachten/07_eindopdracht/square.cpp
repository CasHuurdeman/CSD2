//
// Created by Ciska Vriezenga on 06/12/2022.
//

#include "square.h"
#include "math.h"
Square::Square() : Oscillator ()
{
  std::cout << "Square default - constructor" << std::endl;
}

Square::Square(float frequency, float samplerate) : Oscillator (frequency, samplerate)
{
  std::cout << "Square - constructor\n";
}

Square::~Square () {
  std::cout << "Square - destructor\n";
}

void Square::calculate() {
  sample = amplitude;
  if (phase >= 0.5) {
    sample *= -1.0f;
  }
}