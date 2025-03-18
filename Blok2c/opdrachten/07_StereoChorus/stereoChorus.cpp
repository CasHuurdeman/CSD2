//
// Created by cashu on 22/02/2025.
//
#pragma once
#include "stereoChorus.h"

StereoChorus::StereoChorus(float rate, float depth, float feedback){

    this->rate = rate;
    this->depth = depth;
    this->feedback = feedback;

    chorusL = Chorus(rate, depth, feedback, 0.25f);
    chorusC = Chorus{rate, depth, feedback, 0.0f};
    chorusR = Chorus{rate, depth, feedback, 0.75f};
}

void StereoChorus::applyEffect(const float &input, float &output){
  //TODO - this is now pseudocode

        float outputL;
        float outputC;
        float outputR;

      outputL = chorusL.applyEffect(input);
      outputC = chorusC.applyEffect(input);
      outputR = chorusR.applyEffect(input);

      output1 = outputL + 0.5*outputC;
      output2 = outputR + 0.5*outputC;

}


StereoChorus::~StereoChorus(){
}