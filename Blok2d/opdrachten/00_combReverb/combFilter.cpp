//
// Created by cashu on 13/05/2025.
//

#include "combFilter.h"
#include <iostream>

CombFilter::CombFilter(float D, float g){
  std::cout << "CombFilter - constructor" << std::endl;

  this->D = D;
  this->g = g;

  //TODO - is +1 nodig?
  //Using ceil() because input has to be an int and >= D
  x = new CircularBuffer{static_cast<unsigned int>(ceil(D)) + 1, D};
  y = new CircularBuffer{static_cast<unsigned int>(ceil(D)) + 1, D};

  std::cout << x->getBufferSize() << std::endl;
  std::cout << y->getBufferSize() << std::endl;
}

CombFilter::~CombFilter(){
  std::cout << "CombFilter - destructor" << std::endl;
}


double CombFilter::process(double input) {
 // y(n) = x(n-D) + gy(n-D)
 // y(n) --> y[0]
  x->write(input);

  //TODO (later) - This delay is possible with only one delay line
  //Circular Buffer has a 'read' and 'readBetweenSamples' because interpolation
  // will give an unwanted LPF effect for the APF later
  double output = x->read() + g*y->read();

  y->write(output);

  return output;
}

void CombFilter::setD(float D) {
  this->D = D;

  x->setBufferSize(static_cast<int>(ceil(D)) + 1);
  y->setBufferSize(static_cast<int>(ceil(D)) + 1);
  std::cout << x->getBufferSize() << std::endl;
  std::cout << y->getBufferSize() << std::endl;


  x->setNumSamplesDelay(D);
  y->setNumSamplesDelay(D);

}

float CombFilter::getD(){return D;}

void CombFilter::set_g(float g) {
  this->g = g;
}

float CombFilter::get_g(){return g;}
