//
// Created by cashu on 02/03/2025.
//
#ifndef _triangle_H_
#define _triangle_H_

#include <iostream>
#include "oscillator.h"

class Triangle : public Oscillator
{
public:
    //Constructor and destructor
    Triangle();
    Triangle(float frequency, float samplerate = 44100);
    ~Triangle();

private:
    // calculate the next sample according to Triangle calculation
    void calcNextSample() override;
};

#endif
