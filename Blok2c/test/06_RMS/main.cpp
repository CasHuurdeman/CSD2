//
// Created by cashu on 09/03/2025.
//
#include "square.h"
# include <iostream>

int main() {

    Square sine(500);

    int bufferSize = 4096;

    float* buffer;
    buffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        buffer[i] = sine.genNextSample();
    }

    //POWER:
    float feedback {0.0};
    for (int i = 0; i < bufferSize; i++) {
        feedback = feedback + fabs(buffer[i]);
    }

    std::cout << feedback << std::endl;


    delete [] buffer;

    return 0;
}