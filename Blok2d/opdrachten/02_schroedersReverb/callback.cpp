#include "callback.h"
#include "effect.h"

CustomCallback::CustomCallback (double sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare(int rate) {
    samplerate = (double) rate;
    reverb.prepare(samplerate);
    std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels,
      numOutputChannels, numFrames] = buffer;
  for (int channel = 0u; channel < numInputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {

       outputChannels[0][i] = reverb.processFrame(inputChannels[0][i]);

    }
  }
}

