//
// Created by cashu on 09/03/2025.
//
#include "chorus.h"
#include "interpolation.h"

Chorus::Chorus(float rate, float depth, float feedback){

  //Pirkle: chorus has a delay of 1-30ms, so 1440 maxDelay (for 48000 kHz)
  circBuffer.setBufferSize(1440);
  sine.setFrequency(rate);

  this-> rate = rate;
  this-> depth = depth;
  this-> feedback = feedback;
}

//TODO - look at Pirkle book

void Chorus::applyEffect(const float &input, float &output) {

  // modSignal = (sine.genNextSample() + 1) * 15;
  circBuffer.setNumSamplesDelay(1400);

  output = circBuffer.read();
  // write value to circular buffer
  circBuffer.write(output * feedback + input);
  if (input != 0) {
    std::cout << "haha" << std::endl;
  }
}

Chorus::~Chorus(){
}

//FIXME - use catch or just return instead of throw
//----- Setters -----
void Chorus::setRate(float rate) {
  if (rate < 0.1 || rate > 20) {
    std::cout << "Chorus::setDepth - depth exceeds range [0.1, 20]\n";
  }else {
    this-> rate = rate;
    sine.setFrequency(rate);
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