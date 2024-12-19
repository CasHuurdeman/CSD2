//
// Created by cashu on 05/12/2024.
//
#include <iostream>
#include "square.h"
#include "melody.h"

#ifndef SYNTH_H
#define SYNTH_H

class Synth{
public:
    //constructors
    Synth();
    ~Synth();

    //methods

    float mtof(float midiPitch);
    void updatePitch(Melody& melody, Synth& synth);

    float getSample();
    virtual void tick() = 0;
    virtual void calculate() = 0;
    virtual void doTheThing(float freq) = 0;

    //fields
    float sample;
    float amplitude;
    int midiNote;
};

#endif //SYNTH_H
