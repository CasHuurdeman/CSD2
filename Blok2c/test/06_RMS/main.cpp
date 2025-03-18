//
// Created by cashu on 09/03/2025.
//
#include "sine.h"
# include <iostream>


//TODO -Loudness meter?
int main() {

    Sine sine(500);

    int bufferSize = 4096;

    float* buffer;
    buffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = sine.genNextSample();
    }

    //POWER:
    float feedback {0.0};
    for (int i = 0; i < bufferSize; i++) {
        feedback += (buffer[i] * buffer[i]);
    }

     //--> RMS niet met absoluutstrepen
    std::cout << sqrt(feedback/bufferSize) << std::endl;


    delete [] buffer;

    return 0;
}