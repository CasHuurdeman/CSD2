#include "callback.h"
#include "melody.h"
#include "square.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), sampleRate (sampleRate) {
  std::cout << "Hallo Ciska" << std::endl;
}

void CustomCallback::prepare (int sampleRate) {
  this->sampleRate = sampleRate;
  std::cout << "\nsamplerate: " << sampleRate << "\n";

  updatePitch(melody, square);
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int sample = 0u; sample < numFrames; ++sample) {
      outputChannels[channel][sample] = 0.0f;
      outputChannels[channel][sample] = square.getSample() * amplitude;
      square.tick();

      /* After every sample, check if we need to advance to the next note
       * This is a bit awkward in this scheme of buffers per channel
       *  In a multichannel setting we should update pitches independently per channel!
       */
      if (frameIndex >= noteDelayFactor * sampleRate) {
        frameIndex = 0;
        updatePitch (melody, square);
      } else {
        frameIndex++;
      }
    }
  }
}

float CustomCallback::mtof (float mPitch){
  return 440.0 * pow (2.0, (mPitch - 69.0f) / 12.0f);
}

void CustomCallback::updatePitch (Melody& melody, Square& square) {
  float note = melody.getNote();
  float freq = mtof (note);
  square.setFrequency (freq);
}
