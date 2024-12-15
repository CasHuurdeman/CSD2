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
    void play();

    float mtof(float midiPitch);
    void updatePitch(Melody& melody, Square& square);

    void getSample();
    void tick();
    // virtual void calculate();

    //fields
    float sample;
    float amplitude;
};

#endif //SYNTH_H
