#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>
#include "combReverb.h"
#include "circularBuffer.h"


class CustomCallback : public AudioCallback {
public:
  CustomCallback (double sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  double samplerate = 44100;

  //TODO - change delay time
  std::array<CombReverb,2> stereoVerb {CombReverb(), CombReverb()};

};

#endif //CALLBACK_H
