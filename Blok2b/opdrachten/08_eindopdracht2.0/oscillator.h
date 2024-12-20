#ifndef _Oscillator_H_
#define _Oscillator_H_
#include <iostream>

class Oscillator {
public:
  Oscillator (float frequency = 0, float sampleRate = 44100);
  virtual ~Oscillator();


  void setSamplerate (float sampleRate);
  float getSample();

  void setFrequency (float frequency);
  float getFrequency();

  void tick();

protected:
  // abstract method calculate - needs to be overridden by subclasses
  virtual void calculate() = 0;

  float frequency;
  float amplitude { 0.25f };
  float phase;
  // sample contains the current sample
  float sample;
  float sampleRate;


  float pi = acos(-1.0f);
};

#endif
