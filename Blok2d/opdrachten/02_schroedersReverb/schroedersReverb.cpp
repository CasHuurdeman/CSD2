//
// Created by cashu on 13/05/2025.
//

#include <iostream>
#include "schroedersReverb.h"
#include "delayMath.h"

SchroedersReverb::SchroedersReverb() {
    std::cout << "SchroedersReverb - constructor" << std::endl;
}

SchroedersReverb::~SchroedersReverb() {
    std::cout << "SchroedersReverb - destructor" << std::endl;
}

void SchroedersReverb::prepare(unsigned int samplerate) {
    this->samplerate = samplerate;


    // Using static D values inspired on Schroeder (Pirkle 471)
    CF1 = new CombFilter {DelayMath::msToSamples(30.0f, samplerate), calculate_g(30.0f)};
    CF2 = new CombFilter {DelayMath::msToSamples(35.5f, samplerate), calculate_g(35.5f)};
    CF3 = new CombFilter {DelayMath::msToSamples(41.3f, samplerate), calculate_g(41.3f)};
    CF4 = new CombFilter {DelayMath::msToSamples(45.0f, samplerate), calculate_g(45.0f)};

    APF1 = new APF{DelayMath::msToSamples(2.0f, samplerate), 0.5f};
    APF2 = new APF{DelayMath::msToSamples(3.0f, samplerate), 0.5f};
}


double SchroedersReverb::applyEffect(double input) {
    //CF --> CombFilter

    double output = CF1->process(input) + CF2->process(input)
    + CF3->process(input) + CF4->process(input);

    //for more APF you can do this with a for loop and an array
    output = APF1->process(output);
    output = APF2->process(output);

    return output;
}

float SchroedersReverb::calculate_g(float D) {
    //RT60 is now fixed
    double RT60 = 1000; //ms

    float g = pow(10, (-3*D)/ RT60);

    return g;
}


