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
  float samplerate = 48000;

    //Creating two effects in the callback is the simplest way to create a stereo effect
    //Maybe look into a stereoEffect class/a way to do this out of the callback

    //Stereo delay
  std::array<Delay,2> delays {Delay(0.9, 200, 1000, 0.7),
                                Delay(0.5, 300, 1000, 0.7)};


  //Stereo chorus
  std::array<Chorus, 2> chori{ Chorus(1,0.5,0.0, 0.7, 0.25),
                                Chorus(1,0.5,0.0, 0.7, 0.75) };

  std::array<WaveShaper, 2> waveShapers{WaveShaper(4096),
                                            WaveShaper(4096)};

};
