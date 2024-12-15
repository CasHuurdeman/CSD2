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
    Square();
    Square(double frequency, double samplerate);
    ~Square();

    void calculate();


};

#endif //SQUARE_H
