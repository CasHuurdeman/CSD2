//
// Created by cashu on 09/03/2025.
//
#include "chorus.h"
#include "interpolation.h"
#include "delayMath.h"

Chorus::Chorus(float rate, float depth, float feedback, float phase){

  //Pirkle: chorus has a delay of 1-30ms, so 1440 maxDelay (for 48000 kHz)
  circBuffer.setBufferSize(DelayMath::msToSamples(60, 48000));
  osc.setFrequency(rate);
  osc.setPhase(phase);
  setDryWet(0.7);

  this-> rate = rate;
  this-> depth = depth;
  this-> feedback = feedback;
}

void Chorus::prepare(float samplerate) {
  //TODO - NOTE: example, keeping things 'simple', hence no validation (also in tremolo)
  osc.prepare(samplerate);
  this-> samplerate = samplerate;

}


//TODO - look at Pirkle book
float Chorus::applyEffect(float input) {
  float output;

  modSignal = DelayMath::msToSamples(10, samplerate) + DelayMath::msToSamples((osc.genNextSample() * Interpolation::linMap(depth, 0, 5)), samplerate);

  circBuffer.setNumSamplesDelay((int)modSignal);
  circBuffer.write(output * 0 + input);
  output = circBuffer.read();

  return output;
}


Chorus::~Chorus(){
}


//----- Setters -----
void Chorus::setRate(float rate) {
  if (rate < 0.1 || rate > 20) {
    std::cout << "Chorus::setDepth - depth exceeds range [0.1, 20]\n";
  }else {
    this-> rate = rate;
    osc.setFrequency(rate);
  }
}

void Chorus::setDepth(float depth) {
  if (depth < 0 || depth > 1) {
    std::cout << "Chorus::setDepth - depth exceeds range [0, 1]\n";
  }else
{  this-> depth = depth;}
}

void Chorus::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    std::cout << "Chorus::setFeedback - feedback exceeds range [0, 1\n";
  }else {
    this-> feedback = feedback;
  }
}

//----- Getters -----
float Chorus::getRate() {return rate;}

float Chorus::getDepth() {return depth;}

float Chorus::getFeedback(){return feedback;}