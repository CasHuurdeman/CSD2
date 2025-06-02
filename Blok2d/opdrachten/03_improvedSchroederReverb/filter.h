//
// Created by cashu on 29/05/2025.
//

#pragma once

#include "circularBuffer.h"

class Filter{
public:
    Filter(float D, float g);
    virtual ~Filter();

    virtual double process(double input) = 0;

    void setD(float D);
    float getD();
    //snakecase because g should be lowercase
    void set_g(float g);
    float get_g();

protected:
    //TODO - rethink this class, not every filter needs 2 circbuffers and some may need more
    //TODO - make N buffers in constructor?
    CircularBuffer* x;
    CircularBuffer* y;

    //D is the delay in the combfilter, also the bufferSize (Pirkle p464)
    float D;
    //g is the feedback value (Pirkle p464)
    float g;
};
