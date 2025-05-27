//
// Created by cashu on 13/05/2025.
//

#include "combFilter.h"
#include <iostream>

CombFilter::CombFilter(float D, float g){
  std::cout << "CombFilter - constructor" << std::endl;

  this->D = D;
  this->g = g;

  //Using ceil() because input has to be an int and >= D
  x.setBufferSize(static_cast<int>(ceil(D)));
  y.setBufferSize(static_cast<int>(ceil(D)));

  x.setNumSamplesDelay(D);
  y.setNumSamplesDelay(D);

}

CombFilter::~CombFilter(){
  std::cout << "CombFilter - destructor" << std::endl;
}


double CombFilter::process(double input) {
 // y(n) = x(n-D) + gy(n-D)
 // y(n) --> y[0]

  //TODO - use prints to check if the buffers work

  //TODO (later) - This delay is possible with only one delay line
  //Circular Buffer has a 'read' and 'readBetweenSamples' because interpolation
  // will give an unwanted LPF effect for the APF later
  double output = x.readBetweenSamples() + g*y.readBetweenSamples();
  x.write(input);

  y.write(output);

  return output;
}

void CombFilter::setD(float D) {
  this->D = D;

  x.setBufferSize(static_cast<int>(ceil(D)));
  y.setBufferSize(static_cast<int>(ceil(D)));

  x.setNumSamplesDelay(D);
  y.setNumSamplesDelay(D);

}

float CombFilter::getD(){return D;}

void CombFilter::set_g(float g) {
  this->g = g;
}

float CombFilter::get_g(){return g;}
