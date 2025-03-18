#pragma once
#include "effect.h"
#include "circularBuffer.h"

class Delay : public Effect
{
public:
  Delay() = default;
  Delay(float feedback, float msDelay, float maxMsDelay, float dryWet);
  ~Delay();

  void applyEffect(const float &input, float &output) override;
  void prepare(float samplerate) override;

  void setFeedback(float feedback);
  float getFeedback();


private:
  CircularBuffer circBuffer;

  float msDelay;
  float maxMsDelay;

  float feedback;
  int samplerate;
};
