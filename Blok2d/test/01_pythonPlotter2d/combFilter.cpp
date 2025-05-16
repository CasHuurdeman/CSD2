//
// Created by cashu on 13/05/2025.
//

#include "combFilter.h"

CombFilter::CombFilter(unsigned int D, float g){

  this->D = D;
  this->g = g;

  for(int i = 0; i <= D; i++){
    y.insert(y.begin(), 0);
    x.insert(x.begin(), 0);
  }
}

CombFilter::~CombFilter(){
}

//TODO - is this code good?
double CombFilter::process(double input) {
 // y(n) = x(n-D) + gy(n-D)
 // y(n) --> y[0]

  x.insert(x.begin(), input);
  x.pop_back();

  double output = x[D] + g*y[D];

  y.insert(y.begin(), output);
  y.pop_back();

  return output;
}