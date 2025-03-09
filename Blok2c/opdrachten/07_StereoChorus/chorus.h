//
// Created by cashu on 09/03/2025.
//
#pragma once

#include "triangle.h"
#include "effect.h"
#include "circularBuffer.h"

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
    float* buffer;
    //TODO - make an osc pointer
    Triangle triangle;
    CircularBuffer circBuffer;

    //TODO - change phase of the osc for stereo delay

    //TODO - make a delay in samples to seconds method (or in audio library)
    //rate = LFO freq
    float rate;
    //depth = LFO amp
    //TODO - make depth a normalised value
    float depth;
    float feedback;
    float modSignal;
};
