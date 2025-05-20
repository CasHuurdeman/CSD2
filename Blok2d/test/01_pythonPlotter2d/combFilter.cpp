//
// Created by cashu on 13/05/2025.
//

#include "combFilter.h"
#include <iostream>

CombFilter::CombFilter(unsigned int D, float g){
  std::cout << "CombFilter - constructor" << std::endl;

  this->D = D;
  this->g = g;

  for(int i = 0; i <= D; i++) {
    y.insert(y.begin(), 0);
    x.insert(x.begin(), 0);
  }

  for (int i = 0; i < D; i++) {
    std::cout << x[i] << std::endl;
  }
}

CombFilter::~CombFilter(){
  std::cout << "CombFilter - destructor" << std::endl;
}

//TODO - is this code good?
//TODO - delay in samples or ms?
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

//TODO - use prints to check if the vectors work
void CombFilter::setD(unsigned int D) {
  this->D = D;

  //clear the vectors before filling them again with zero's
  x.clear();
  y.clear();

  for(int i = 0; i <= D; i++) {
    y.insert(y.begin(), 0);
    x.insert(x.begin(), 0);
  }

}

unsigned int CombFilter::getD(){return D;}

void CombFilter::set_g(float g) {
  this->g = g;
}

float CombFilter::get_g(){return g;}
