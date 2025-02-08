//
// Created by cashu on 08/02/2025.
//

#ifndef EFFECT_H
#define EFFECT_H

class Effect{
  public:
     Effect();
     ~Effect();

     void prepare(float samplerate);
     float processFrame(float sample);

  private:

}

#endif //EFFECT_H
