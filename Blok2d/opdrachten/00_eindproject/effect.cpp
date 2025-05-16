#include "effect.h"
#include <iostream>

Effect::Effect(double dryWet) {
  setDryWet(dryWet);
}

Effect::~Effect() {}

// process frame
void Effect::processFrame(const double &input, double &output)
{
  if (bypassOn == false) {
    applyEffect(input, output);
    output = input * wetDry + output * dryWet;

    // TODO - WHY?: cache output samples
    m_sample = output;
  }
  else{output = input;}
}

// returns the last outputted sample
double Effect::getSample()
{
  return m_sample;
}

void Effect::setDryWet(float dryWet)
{
  if(dryWet < 0 || dryWet > 1) {
    throw "Effect::setDryWet - dryWet value is not in range [0, 1]";
  }
  this->dryWet = dryWet;
  // cache 1.0 - dryWet used to calculate mix of dry wet signal
  wetDry = 1.0f - dryWet;
}
