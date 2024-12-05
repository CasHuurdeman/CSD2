#ifndef _SINE_H_
#define _SINE_H_

#include "oscillator.h"

class Sine : public Oscillator
{
public:
  //Constructor and destructor
  Sine(float frequency, float samplerate = 44100);
  ~Sine();

  void tick();


};

#endif