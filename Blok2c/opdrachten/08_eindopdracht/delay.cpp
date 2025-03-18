#include "delay.h"
#include <iostream>
#include "delayMath.h"

Delay::Delay(float feedback, float msDelay, float maxMsDelay, float dryWet){

  setDryWet(dryWet);

  this-> feedback = feedback;
  this->msDelay = msDelay;
  this->maxMsDelay = maxMsDelay;
}

void Delay::prepare(float samplerate) {
  //TODO - NOTE: example, keeping things 'simple', hence no validation (also in tremolo)
  this-> samplerate = samplerate;

  circBuffer.setBufferSize(DelayMath::msToSamples(maxMsDelay, samplerate));
  circBuffer.setNumSamplesDelay(DelayMath::msToSamples(msDelay, samplerate));
}

Delay::~Delay(){
}


// override base class method
// applies delay effect to the input frame and stores it to the output frame
void Delay::applyEffect(const float &input, float &output)
{
  circBuffer.write(output * feedback + input);
  output = circBuffer.read();
}


// sets the feedback value, should be in range [0, 1]
void Delay::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    throw "Delay::setFeedback - feedback exceeds range [0, 1]";
  }
  this->feedback = feedback;
}
