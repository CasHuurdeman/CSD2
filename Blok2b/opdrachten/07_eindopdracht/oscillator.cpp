#include "oscillator.h"

Oscillator::Oscillator (float frequency, float sampleRate)
  : frequency (frequency),
    amplitude (0.25f),
    phase (0),
    sample (0),
    sampleRate (sampleRate) {
}


Oscillator::~Oscillator() {}

void Oscillator::setSamplerate (float sampleRate) {
  this->sampleRate = sampleRate;
}

float Oscillator::getSample() { return sample; }


void Oscillator::setFrequency (float frequency) {
  this->frequency = frequency;
}

float Oscillator::getFrequency() { return frequency; }

//function to tick to the new sample
void Oscillator::tick() {
  // increment the phase to allow calculation of next sample (this can be done more efficiently)
  phase += frequency / sampleRate;
  // wrap the phase to interval [0, 1]
  if (phase > 1) phase -= 1.0f;
  // calculate sample for the incremented phase
  calculate();
}