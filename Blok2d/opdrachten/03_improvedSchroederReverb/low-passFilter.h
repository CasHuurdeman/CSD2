//
// Created by cashu on 31/05/2025.
//

#pragma once


#include "filter.h"

class LPF{
public:
    // APF() = default;
    LPF(float g);
    ~LPF();

    double process(double input);

private:
    double y1 = 0.0;
    float g = 0.0f;
};

