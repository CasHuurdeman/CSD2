#include <iostream>
#include "triangle.h"
#include "sine.h"
#include <audioToFile.h>
#include "diracDelta.h"


class IIRFilter {
public:
  float process(float input) {
    // Y[n] = X[n] + aY[n-1]
    feedback = a * input + (a * feedback);
    return feedback;
  }

  void setCoefficient(float coefficient) {
    // Do not exceed 1, for the safety of all our ears
    a = coefficient;
  }

private:
  float feedback { 0.0 };
  float a { 0.0 }; // Coefficient "a" is mostly used for feedback lines

};

int main() {
  int samplerate = 48000;

  Sine osc(0);
  DiracDelta dirac;
  IIRFilter filter;
  filter.setCoefficient(0.5);


  const std::string sourcePath = SOURCE_DIR;
  WriteToFile fileWriter(sourcePath + "/output.csv", true);


  //Working on convolution, now dirac delta response of the system
  for (int i = 0; i <10; i++) {
    fileWriter.write(std::to_string(filter.process(dirac.givePulse())) + "\n");
  }

  // for (int freq = 0; freq < (0.5f * samplerate) + 1; freq++) {
  //   osc.setFrequency(freq);
  //   std::cout << freq << std::endl;
  //   fileWriter.write(std::to_string(filter.process(osc.genNextSample())) + "\n");
  // }

  return 0;
}
