//
// Created by cashu on 13/05/2025.
//

#include "combFilter.h"
#include <iostream>

CombFilter::CombFilter(unsigned int D, float g){
  std::cout << "CombFilter - constructor" << std::endl;

  this->D = D;
  this->g = g;

  x.setBufferSize(D);
  y.setBufferSize(D);

  x.setNumSamplesDelay(D);
  y.setNumSamplesDelay(D);


}

CombFilter::~CombFilter(){
  std::cout << "CombFilter - destructor" << std::endl;
}

//TODO - is this code good?
//TODO - delay in samples or ms?
double CombFilter::process(double input) {
 // y(n) = x(n-D) + gy(n-D)
 // y(n) --> y[0]

  x.write(input);

  double output = x.read() + g*y.read();

  y.write(output);

  return output;
}

//TODO - use prints to check if the vectors work
void CombFilter::setD(unsigned int D) {
  this->D = D;

  x.setBufferSize(D);
  y.setBufferSize(D);

  x.setNumSamplesDelay(D);
  y.setNumSamplesDelay(D);

}

unsigned int CombFilter::getD(){return D;}

void CombFilter::set_g(float g) {
  this->g = g;
}

float CombFilter::get_g(){return g;}
