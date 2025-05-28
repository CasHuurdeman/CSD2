//
// Created by cashu on 28/05/2025.
//

#include <iostream>
#include "circularBuffer.h"

int main(){

  CircularBuffer* CircBuffer;

  CircBuffer = new CircularBuffer{10,5};

  for (int i = 0; i < 15; i++) {

    std::cout << "i: " << CircBuffer->read() << std::endl;
  }



  return 0;
}