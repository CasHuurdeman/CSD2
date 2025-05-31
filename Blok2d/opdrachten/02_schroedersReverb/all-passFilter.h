//
// Created by cashu on 29/05/2025.
//

#pragma once

#include "filter.h"

class APF : public Filter{
public:
  // APF() = default;
  APF(float D, float g);
  ~APF() override;

  double process(double input) override;

};
