//
// Created by cashu on 15/12/2024.
//
#include "oscillator.h"
#include "synth.h"
#include "sine.h"
#include <array>


#ifndef ADDITIVESYNTH_H
#define ADDITIVESYNTH_H

class AdditiveSynth : public Synth {
public:
    AdditiveSynth();
    ~AdditiveSynth();

    void tick() override;
    void setFrequency(float freq) override;


    void printArray();

protected:
    void  calculate();

    std::array <Sine, 2> sines;
};

#endif //ADDITIVESYNTH_H
