//
// Created by cashu on 12/03/2025.
//

#pragma once

class delayMath{
public:

  static float samplesToMs(int samples, int samplerate){
    return ((samples*1000.0f)/samplerate);
  };

  static int msToSamples(float ms, int samplerate){
    return (ms*samplerate)/1000.0f;
  };


};