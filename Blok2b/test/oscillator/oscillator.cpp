
#include "oscillator.h"


void Oscillator::setFreq(int f){
    freq = f;
};

void Oscillator::setAmp(float A){
    amp= A;
};

int Oscillator::getFreq(){
    return freq;
};

float Oscillator::getAmp(){
    return amp;
};


Oscillator::Oscillator()
{
    std::cout << "Inside Oscillator constructor\n";

    setFreq(440);
    setAmp(0.5);
};

Oscillator::~Oscillator()
{
  std::cout << "Inside Oscillator destructor\n";
};