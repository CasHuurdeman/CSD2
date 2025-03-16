#include "callback.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    tremolo.prepare(rate);
    chorus.setBypass(false);
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
  float sample1, sample2;

  for (int channel = 0u; channel < numInputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {
      //TODO - effect chain dynamisch met pointers naar verschillende effect objecten

      // tremolo.processFrame(inputChannels[channel][i],  outputChannels[channel][i]);
      // delay.processFrame(sample1,  sample2);
      // waveShaper.processFrame(sample2, sample1);
      chorus.processFrame(inputChannels[channel][i], outputChannels[channel][i]);
    }
  }
}




