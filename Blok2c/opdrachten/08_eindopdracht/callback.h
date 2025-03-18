#pragma once

#include <audiocomponent.h>
#include "tremolo.h"
#include "delay.h"
#include "waveShaper.h"
#include "chorus.h"


class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  float samplerate = 44100;
  Tremolo tremolo = Tremolo(6, 1);
  Delay delay = Delay(0.5f, 100, 500, 0.7);
  WaveShaper waveShaper = WaveShaper(4096);


  //L and R channels of LCR chorus (Pirkle)
  std::array<Chorus, 2> chori{ Chorus(1,0.5,0.0f, 0.7, 0.25f),
                                Chorus(1,0.5,0.0f, 0.7, 0.75f) };
  //C channel of LCR chorus (Pirkle)
  Chorus chorus = Chorus(1,0.5,0.0f, 0.7, 0.0f);

};
