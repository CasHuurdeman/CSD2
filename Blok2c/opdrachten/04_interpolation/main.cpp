//
// Created by cashu on 11/02/2025.
//
#include <iostream>
#include "interpolation.h"

int main(){

  std::cout << Interpolation::nnMap(-1.25, 10, 20) << std::endl;
  std::cout << Interpolation::linMap(0.25, 10, 20) << std::endl;
  std::cout << Interpolation::mapInRange(22.5, 10, 20, 20 , 30) << std::endl;
};