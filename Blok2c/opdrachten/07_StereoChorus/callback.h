#pragma once

#include <audiocomponent.h>
#include "tremolo.h"
#include "delay.h"
#include "waveShaper.h"


class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Tremolo tremolo = Tremolo(6, 1);
  Delay delay;
  //FIXME - verkeerde haakjes?
  WaveShaper waveShaper = WaveShaper(4096);

};
