//
// Created by cashu on 15/12/2024.
//
#include "oscillator.h"
#include "synth.h"

#ifndef ADDITIVESYNTH_H
#define ADDITIVESYNTH_H

class AdditiveSynth : public Synth {
public:
    AdditiveSynth();
    ~AdditiveSynth();

private:
    //  oscillator: Oscillator;

protected:
    void  calculate();
};

#endif //ADDITIVESYNTH_H
