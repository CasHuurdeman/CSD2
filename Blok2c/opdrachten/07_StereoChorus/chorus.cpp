//
// Created by cashu on 09/03/2025.
//
#include "chorus.h"

Chorus::Chorus(float rate, float depth, float feedback){

  //Pirkle: chorus has a delay of 1-30ms, so 1440 maxDelay (for 48000 kHz)
  circBuffer.setBufferSize(1440);
  triangle.setFrequency(rate);

  this-> rate = rate;
  this-> depth = depth;
  this-> feedback = feedback;
}


void Chorus::applyEffect(const float &input, float &output) {

  modSignal = triangle.genNextSample() * depth;
  //FIXME - modsignal should be an integer of course --> use interpolation?
  circBuffer.setNumSamplesDelay(modSignal);

  //TODO - maybe use a namespace for this?
  output = circBuffer.buffer[circBuffer.getReadHead()];
  circBuffer.wrapRH();
  // write value to circular buffer
  circBuffer.buffer[circBuffer.getWriteHead()] = output * feedback + input;
  circBuffer.wrapWH();
}


Chorus::~Chorus(){
}


//----- Setters -----
void Chorus::setRate(float rate) {
  if (rate < 0.1 || rate > 20) {
    throw "Chorus::setDepth - depth exceeds range [0.1, 20]";
  }
  this-> rate = rate;
  triangle.setFrequency(rate);
}

void Chorus::setDepth(float depth) {
  if (depth < 0 || depth > 1) {
    throw "Chorus::setDepth - depth exceeds range [0, 1]";
  }
  this-> depth = depth;
}

void Chorus::setFeedback(float feedback)
{
  if(feedback < 0 || feedback > 1) {
    throw "Chorus::setFeedback - feedback exceeds range [0, 1]";
  }
  this-> feedback = feedback;
}

//----- Getters -----
float Chorus::getRate() {return rate;}

float Chorus::getDepth() {return depth;}

float Chorus::getFeedback(){return feedback;}