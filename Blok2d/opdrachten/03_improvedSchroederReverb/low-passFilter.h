//
// Created by cashu on 31/05/2025.
//

#pragma once


#include "filter.h"

class LPF : public Filter{
public:
    // APF() = default;
    LPF(float D, float g);
    ~LPF() override;

    double process(double input) override;
};

