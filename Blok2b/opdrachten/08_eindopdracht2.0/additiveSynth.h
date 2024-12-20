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


    void setNumOfHarmonics(int numOfHarmonics);


protected:
    void  calculate();

    void fillSines();

    int numOfHarmonics = 10;

    std::vector <Sine> sines;
};

#endif //ADDITIVESYNTH_H
