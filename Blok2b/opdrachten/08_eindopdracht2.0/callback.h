#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "oscillator.h"
//#include "sine.h"
//#include "square.h"
#include "melody.h"
#include "organSynth.h"
#include "additiveSynth.h"

class CustomCallback : public AudioCallback {
public:
  CustomCallback (float sampleRate);
  void prepare (int rate) override;
  void process (AudioBuffer buffer) override;


private:
  float sampleRate;

//  OrganSynth organSynth;
//  AdditiveSynth additiveSynth;
  Synth* synth;

  float amplitude = 0.25;
  Melody melody;
  int frameIndex = 0;

  /* instead of using bpm and specifying note lenghts we'll make every note
   * equal length and specify the delay between notes in terms of the samplerate
   *
   * A note of say 500 msec or 0.5 sec, takes 0.5*samplerate samples to be played
   */
  float noteDelayFactor = 0.1;

};

#endif  //CALLBACK_H
