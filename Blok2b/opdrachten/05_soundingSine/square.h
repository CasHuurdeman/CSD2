//
// Created by cashu on 05/12/2024.
//
#include "oscillator.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Oscillator
{
public:
    //Constructor and destructor
    Square(float frequency, float samplerate = 44100);
    ~Square();

    void tick();


};

#endif //SQUARE_H
