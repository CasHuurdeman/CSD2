//
// Created by cashu on 13/05/2025.
//

#pragma once

#include <iostream>
#include <vector>
#include "circularBuffer.h"

class CombFilter{
public:
  CombFilter() = default;
  CombFilter(unsigned int D, float g);
  ~CombFilter();

  double process(double input);

  void setD(unsigned int D);
  unsigned int getD();
  //snakecase because g should be lowercase
  void set_g(float g);
  float get_g();

private:

  CircularBuffer x;
  CircularBuffer y;

  //D is the delay in the combfilter, also the bufferSize (Pirkle p464)
  unsigned int D;
  //g is the feedback value (Pirkle p464)
  float g;

};
