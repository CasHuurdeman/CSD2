#pragma once
#include "effect.h"
#include "circularBuffer.h"
#include "RMS.h"

class Delay : public Effect
{
public:
  Delay() = default;
  Delay(float feedback, float msDelay, float maxMsDelay, float dryWet);
  ~Delay();

  void applyEffect(const float &input, float &output) override;
  void prepare(int samplerate) override;

  void setFeedback(float feedback);
  float getFeedback();
  void setDelay(float msDelay);


private:
  CircularBuffer circBuffer;

  float msDelay = 0.0f;
  float maxMsDelay = 0.0f;

  float feedback = 0.0f;
  int samplerate = 48000;

  // buffer of 3 seconds
  RMS RMS{3000};
};
