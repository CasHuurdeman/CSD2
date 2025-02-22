//
// Created by cashu on 20/02/2025.
//
#include <iostream>

#define BUFSIZE 10

// how far can you go outside your assigned space?
#define ILLEGAL_OVERSHOOT 10


int main()
{
    // request some memory and let 'buffer' point to it
    int * buffer = new int[BUFSIZE];

    // initialise the buffer
    for(int i=0; i<BUFSIZE; i++){
        buffer[i] = BUFSIZE-i;
    }

    // show buffer contents and a bit more
    for(int i=0; i<BUFSIZE+ILLEGAL_OVERSHOOT; i++){
        std::cout << buffer[i] << std::endl;
    }
}