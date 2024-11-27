
#include <iostream>

#include "instrument.h"

Instrument::Instrument(){
    std::cout << "instrument - constructor" << std::endl;

};

Instrument::~Instrument(){
    std::cout << "instrument - destructor" << std::endl;

};

void Instrument::setHighFreq(float f){
    highFreq = f;
};

void Instrument::setLowFreq(float f){
    lowFreq = f;
};

void Instrument::play(){
    std::cout << "Instrument playing" << std::endl;
}


float Instrument::getHighFreq(){
    return highFreq;
};

float Instrument::getLowFreq(){
    return lowFreq;
};

