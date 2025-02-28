#include "callback.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    tremolo.prepare(rate);
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
  float sample1, sample2;

  for (int channel = 0u; channel < numInputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {
      tremolo.processFrame(inputChannels[channel][i],  sample1);
      delay.processFrame(sample1,  sample2);
      waveShaper.processFrame(sample2, outputChannels[channel][i]);
    }
  }
}
