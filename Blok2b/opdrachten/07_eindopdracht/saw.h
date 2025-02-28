//
// Created by cashu on 05/12/2024.
//
#include "oscillator.h"

#ifndef SAW_H
#define SAW_H

class Saw : public Oscillator
{
public:
    //Constructor and destructor
    Saw(float frequency, float samplerate = 44100);
    ~Saw();

protected:
    void calculate();


};

#endif //SAW_H
