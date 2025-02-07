//
// Created by cashu on 03/02/2025.
//

#ifndef TREMOLO_H
#define TREMOLO_H

#include <sine.h>

class Tremolo {
  public:
   Tremolo(float freq, float depth = 1);
   ~Tremolo();

   void setModFrequency(float freq);
   void prepare(float samplerate);
   float processFrame(float sample);

   private:
     float modDepth = 0;
     Sine sine;

};

#endif //TREMOLO_H


