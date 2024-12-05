//
// Created by cashu on 05/12/2024.
#include "oscillator.h"
#include <iostream>

Oscillator::Oscillator()
{
  std::cout << "Oscillator - constructor" << std::endl;
}

Oscillator::~Oscillator(){
  std::cout << "Oscillator - destructor" << std::endl;
}


void Oscillator::setSamplerate(float samplerate) {
  this->samplerate =samplerate;
}

float Oscillator::getSample() {
  return sample;
}

//getters and setters
void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency()
{
  return frequency;
}