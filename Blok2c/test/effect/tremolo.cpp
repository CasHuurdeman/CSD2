//
// Created by cashu on 03/02/2025.
//
#include "tremolo.h"
#include <iostream>

Tremolo::Tremolo(float freq, float depth){
  std::cout << "Tremolo constructor" << std::endl;

  modDepth = depth;
  setModFrequency(freq);
}

Tremolo::~Tremolo(){
  std::cout << "Tremolo destructor" << std::endl;
}

void Tremolo::setModFrequency(float freq){
  if(freq <= 20 && freq > 0){
    sine.setFrequency(freq);
  }
  else std::cout << "This is not a valid frequency" << std::endl;
}

float Tremolo::processFrame(float freq){
  float modSignal = sine.genNextSample() * -0.5 + 0.5;
  modSignal *= modDepth;
  modSignal += 1 - modDepth;

  return modSignal;
}

void Tremolo::prepare(float samplerate){
  sine.prepare(samplerate);
}

