//
// Created by cashu on 28/05/2025.
//

#include <iostream>
#include "circularBuffer.h"

//TODO - check where "-7.58636e+298" comes from
int main(){

  CircularBuffer* CircBuffer;

  CircBuffer = new CircularBuffer{10,5};

  CircBuffer->setNumSamplesDelay(25);

  for (int i = 0; i < 15; i++) {
    CircBuffer->write(i);
    std::cout << i << ": " << CircBuffer->read() << std::endl;
  }

  std::cout << CircBuffer->getNumSamplesDelay() << std::endl;


  return 0;
}