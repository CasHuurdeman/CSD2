#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "oscillator.h"
#include "melody.h"
#include "organSynth.h"
#include "additiveSynth.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback(float sampleRate);
  ~CustomCallback();

  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;


private:
  float sampleRate;

  Synth* synth;
  Melody melody;

  int frameIndex = 0;

};

#endif  //CALLBACK_H
