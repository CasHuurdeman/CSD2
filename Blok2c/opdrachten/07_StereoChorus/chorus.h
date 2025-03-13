//
// Created by cashu on 09/03/2025.
//
#pragma once

#include "sine.h"
#include "effect.h"
#include "circularBuffer.h"
#include "delayMath.h"

//minDelay is not a user parameter
class Chorus : public Effect{
public:
    Chorus(float rate, float depth, float feedback);
    ~Chorus();

    void applyEffect(const float &input, float &output) override;

    void setRate(float rate);
    void setDepth(float depth);
    void setFeedback(float feedback);

    float getRate();
    float getDepth();
    float getFeedback();


private:
    //TODO - make an osc pointer
    //FIXME - TRIANGLE
    Sine sine;
    CircularBuffer circBuffer;

    //TODO - change phase of the osc for stereo delay

    //rate = LFO freq
    float rate;
    //depth = LFO amp
    float depth;
    float feedback;
    float modSignal = 0;
};
