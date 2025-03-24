#include "delay.h"
#include <iostream>
#include "delayMath.h"
#include "interpolation.h"

Delay::Delay(float feedback, float msDelay, float maxMsDelay, float dryWet){

  setDryWet(dryWet);

  this-> feedback = feedback;
  this->msDelay = msDelay;
  this->maxMsDelay = maxMsDelay;
}

void Delay::prepare(int samplerate) {
  this-> samplerate = samplerate;

  RMS.prepare(samplerate);

  circBuffer.setBufferSize(DelayMath::msToSamples(maxMsDelay, samplerate));
  circBuffer.setNumSamplesDelay(DelayMath::msToSamples(msDelay, samplerate));
}

Delay::~Delay(){
}


// override base class method
// applies delay effect to the input frame and stores it to the output frame
void Delay::applyEffect(const float &input, float &output){

  float RMSValue = RMS.calculateRMS(input);

  //normally RMSValue is ~0.07
  while (RMSValue > 0.1) {
    RMSValue = RMSValue*0.5;
  }

  // setFeedback(Interpolation::mapInRange(RMS.calculateRMS(input), 0.025f, 0.1, 0.0f, 1.0f));
  setFeedback(5 * RMS.calculateRMS(input));

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

void Delay::setDelay(float msDelay) {
  if(feedback < 0 || feedback > 10000) {
    throw "Delay::setDelay - delay exceeds range [0, 10 000]";
  }
  this->msDelay = msDelay;
  circBuffer.setNumSamplesDelay(DelayMath::msToSamples(msDelay, samplerate));
}
