
#include <iostream>

// 3 type access specifiers:
// public, protected, private

class Oscillator
{
    //constructors
public:
  Oscillator();
  ~Oscillator();

    //methods
protected:
    void setFreq(int f);
    void setAmp(float A);

public:
    int getFreq();
    float getAmp();

protected:
    // fields
    int freq = 0;
    float amp = 0.0;

};