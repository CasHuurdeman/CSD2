//
// Created by cashu on 11/02/2025.
//
#include "interpolation.h"
#include <iostream>


float Interpolation::nnMap(float value, float low, float high){
    //check if value is withing valid range
    if(value < 0){
        std::cout << "ERROR Interpolation::nnMap \n That's not between 0 and 1";
        return low;
    }
    if(value > 1){
        std::cout << "ERROR Interpolation::nnMap \n That's not between 0 and 1";
        return high;
    }
    //at this point the value is within range
    if(value < 0.5) return low;
    return high;
}

float Interpolation::linMap(float value, float low, float high){
    //check if value is withing valid range
    if(value < 0){
        std::cout << "ERROR Interpolation::linMap \n That's not between 0 and 1 (<0)";
        return low;
    }
    if(value > 1){
        std::cout << "ERROR Interpolation::linMap \n That's not between 0 and 1 (>1)";
        return high;
    }
    //at this point the value is within range
    return (low * (1.0 - value))+(high * value);
}

float Interpolation::mapInRange(float value, float fromLow, float fromHigh,
                     float toLow, float toHigh){

    float ratio = (value - fromLow)/(fromHigh - fromLow);

    return (toLow * (1.0 - ratio))+(toHigh * ratio);

}