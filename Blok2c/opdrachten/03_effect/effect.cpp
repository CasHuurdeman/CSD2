//
// Created by cashu on 08/02/2025.
//

#include "effect.h"
#include <iostream>

Effect::Effect(){
  std::cout<<"Effect::Effect()"<<std::endl;
}

Effect::~Effect(){
  std::cout<<"Effect::~Effect()"<<std::endl;
}

float Effect::processFrame(float sample){


  return sample;
}

void Effect::prepare(float samplerate){

}