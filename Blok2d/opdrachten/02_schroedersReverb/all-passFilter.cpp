//
// Created by cashu on 29/05/2025.
//

#include "all-passFilter.h"
#include <iostream>

//TODO - is dit hoe ik mijn filter base class initialiseer?
APF::APF(float D, float g): Filter(D, g){
  std::cout << "APF - constructor" << std::endl;
}

APF::~APF() {
  std::cout << "APF - destructor" << std::endl;
}

double APF::process(double input) {
  x->write(input);

  //TODO (later) - This delay is possible with only one delay line --> make a separate x(n)= (or w(n)=) and y(n)= ???
  //Circular Buffer has a 'read' and 'readBetweenSamples' because interpolation
  // will give an unwanted LPF effect for the APF
  double output = g*input + x->read() - g*y->read();

  y->write(output);

  return output;
}