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
  Delay delay;
  WaveShaper waveShaper = WaveShaper(4096);

  // Chorus chorus = Chorus(1,0.5,0.0f, 0.0f);

  //only 2 chori because stereo
  std::array<Chorus, 2> chori{ Chorus(1,0.5,0.0f, 0.25f),
                                Chorus(1,0.5,0.0f, 0.75f) };
};
