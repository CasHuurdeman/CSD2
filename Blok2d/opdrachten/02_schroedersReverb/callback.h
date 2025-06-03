#pragma once

#include <audiocomponent.h>
#include "SchroedersReverb.h"
#include "circularBuffer.h"


class CustomCallback : public AudioCallback {
public:
  CustomCallback (double sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  double samplerate = 44100;

  //TODO - change delay time
  std::array<SchroedersReverb,2> stereoVerb {SchroedersReverb(), SchroedersReverb()};

};

