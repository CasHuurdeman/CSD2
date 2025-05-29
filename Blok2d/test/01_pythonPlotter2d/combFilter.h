//
// Created by cashu on 29/05/2025.
//

#pragma once

#include "filter.h"

class CombFilter : public Filter{
public:
    // APF() = default;
    CombFilter(float D, float g);
    ~CombFilter() override;

    double process(double input) override;

};
