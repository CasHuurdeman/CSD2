//
// Created by cashu on 15/12/2024.
//
#include "oscillator.h"
#include "synth.h"
#include "sine.h"
#include <vector>


#ifndef ADDITIVESYNTH_H
#define ADDITIVESYNTH_H

class AdditiveSynth : public Synth {
public:
    AdditiveSynth();
    ~AdditiveSynth();

    void tick() override;
    void setFrequency(float freq) override;


    void printArray();
    int numOfHarmonics = 50;

protected:
    void  calculate();

    void fillSines();

    std::vector <Sine> sines;
};

#endif //ADDITIVESYNTH_H
