//
// Created by cashu on 02/03/2025.
//
#include "LFO.h"

LFO::LFO(float rate, float depth, Waveform waveform){



  //object is called SineWave becaase "sine" is already in enum
  switch (waveform){
    case sine: {
      FastSine SineWave(rate);
    }
      break;
    case square: {
      Square SquareWave(rate);
    }
      break;
    case saw: {
      Saw SawWave(rate);
    }
      break;
    case triangle: {
      Triangle TriangleWave(rate);
    }
      break;
  }
}
