//
// Created by cashu on 09/03/2025.
//
#pragma once

#include "sine.h"
#include "triangle.h"
#include "effect.h"
#include "circularBuffer.h"
#include "delayMath.h"

//minDelay is not a user parameter
class Chorus : public Effect{
public:
    Chorus() = default;
    Chorus(float rate, float depth, float feedback, float phase);
    ~Chorus();

    //
    void applyEffect(const float &input, float &output) override {};

    float applyEffect(float input);
    void prepare(float samplerate) override;

    void setRate(float rate);
    void setDepth(float depth);
    void setFeedback(float feedback);

    float getRate();
    float getDepth();
    float getFeedback();


private:
    //TODO - make an osc pointer (if I have too much time)
    //TODO - check sound with triangle
    Triangle osc;
    CircularBuffer circBuffer;

    //rate = LFO freq
    float rate;
    //depth = LFO amp
    float depth;
    float feedback;
    float modSignal = 0;
    int samplerate;
};
