//
// Created by cashu on 16/02/2025.
//
#include <iostream>

int main(){
  int k = 10;
  float input;

    // for (float i = 0; i<10; i++) {
    //   input = i/10;
    //   // std::cout << i << std::endl;
    //  std::cout << 1/atan(k) * atan(k * input) <<std::endl;
    // }

    float* buffer;
  int bufferSize = 4096;
  buffer = new float(bufferSize);
  for (int i = 0; i < bufferSize; i++) {
    buffer[i] = 0;
  }
    //
    // for (int i = 0; i < bufferSize; i++) {
    //   float input = (float)i/bufferSize;
    //   // buffer[i] = 1/atan(k) * atan(k * input);
    // }
  std::cout<< "hey" << std::endl;
    std::cout << buffer[2] << std::endl;


  return 0;
}
