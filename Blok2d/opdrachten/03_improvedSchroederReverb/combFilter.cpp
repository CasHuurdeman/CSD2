//
// Created by cashu on 29/05/2025.
//

#include "combFilter.h"
#include <iostream>

//TODO - is dit hoe ik mijn filter base class initialiseer?
CombFilter::CombFilter(float D, float g): Filter(D, g){
    std::cout << "CombFilter - constructor" << std::endl;
}

CombFilter::~CombFilter() {
    std::cout << "CombFilter - destructor" << std::endl;
}

double CombFilter::process(double input) {
    // y(n) = x(n-D) + gy(n-D)
    // y(n) --> y[0]
    x->write(input);

    //TODO (later) - This delay is possible with only one delay line
    //Circular Buffer has a 'read' and 'readBetweenSamples' because interpolation
    // will give an unwanted LPF effect for the CombFilter
    double output = x->read() + g*y->read();

    y->write(output);

    return output;
}