#include "callback.h"
#include "effect.h"

CustomCallback::CustomCallback (double sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare(int rate) {
    samplerate = rate;

    //i < 1 because of a stereo setup
    for (int i = 0; i < 2; i++) {
    stereoVerb[i].prepare(samplerate);
    }
    std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels,
      numOutputChannels, numFrames] = buffer;
  for (int channel = 0u; channel < numInputChannels; channel++) {
    for (int i = 0u; i < numFrames; i++) {

        //FIXME
        outputChannels[channel][i] = stereoVerb[channel].processFrame(inputChannels[0][i]);

    }
  }
}

