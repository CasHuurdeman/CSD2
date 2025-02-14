//
// Created by cashu on 11/02/2025.
//
#include "interpolation.h"
#include <iostream>


// TODO - Error message is now hacked because it has to output a float (0 in this case)<--fix this
float Interpolation::nnMap(float value, float low, float high){
    if(value < 0 or value > 1){
        std::cout << "ERROR Interpolation::nnMap \n Thats not between 1 and ";
    }
    else if(value < 0.5) return low;
    else return high;
}

float Interpolation::linMap(float value, float low, float high){
    if(value < 0 or value > 1){
        std::cout << "ERROR Interpolation::linMap \n Thats not between 0 and 1" << std::endl;
    }
    else return (low * (1.0 - value))+(high * value);
}

float Interpolation::mapInRange(float value, float fromLow, float fromHigh,
                     float toLow, float toHigh){

    float ratio = (value - fromLow)/(fromHigh - fromLow);

    return (toLow * (1.0 - ratio))+(toHigh * ratio);

}