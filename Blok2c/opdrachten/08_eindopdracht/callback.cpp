#include "callback.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {}

void CustomCallback::prepare(int rate) {
    samplerate = (float) rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";
    tremolo.prepare(rate);

  //Only for stereo, so 2 channels
  for (int channel = 0u; channel < 2; channel++) {
    chori[channel].prepare(rate);
    chori[channel].setBypass(false);
  }
}

void CustomCallback::process(AudioBuffer buffer) {
  auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
  float sample1, sample2;

  //TODO - make an array with effects
  for (int channel = 0u; channel < numInputChannels; channel++) {

    for (int i = 0u; i < numFrames; i++) {
      //TODO - effect chain dynamisch met pointers naar verschillende effect objecten

      // tremolo.processFrame(inputChannels[channel][i],  outputChannels[channel][i]);
      // delay.processFrame(sample1,  sample2);
      // waveShaper.processFrame(sample2, sample1);


      //inputChannels[0] because of a mono input (this could be variable if I wanted a stereo input)
      chori[channel].processFrame(inputChannels[0][i], outputChannels[channel][i]);
    }
  }
}




