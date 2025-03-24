#include "callback.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";

  //Only for stereo, so 2 channels
  for (int channel = 0u; channel < 2; channel++) {
    chori[channel].prepare(rate);
    chori[channel].setBypass(false);

    delays[channel].prepare(rate);
    delays[channel].setBypass(false);

    waveShapers[channel].setBypass(true);
  }
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

  std::array<float, 2> samples1 {0.0, 0.0};
  std::array<float, 2> samples2 {0.0, 0.0};


  for (int channel = 0u; channel < numInputChannels; channel++) {

    for (int i = 0u; i < numFrames; i++) {
      //TODO (later) - make effect chain dynamic with pointers

      waveShapers[channel].processFrame(inputChannels[0][i], samples1[channel]);

      delays[channel].processFrame(samples1[channel], samples2[channel]);

      //inputChannels[0] because of a mono input (this could be variable if I wanted a stereo input)
        chori[channel].processFrame(samples2[channel], outputChannels[channel][i]);
    }
  }
}




