#include <iostream>
#include "triangle.h"
#include "sine.h"
#include <audioToFile.h>
#include "diracDelta.h"
#include <complex>
#include "filters.h"


int main() {

  int samplerate = 48000;
  int halfSamplerate = (int)(0.5f*samplerate);

  float currentSample = 0.0f;
  float highestSample = 0.0f;

  Sine osc{0};

  FIRFilter filter;
  filter.setCoefficient(0.5f);
  // filter.setA1Coefficient(0.5f);
  // filter.setA2Coefficient(0.5f);


  const std::string sourcePath = SOURCE_DIR;
  WriteToFile fileWriter(sourcePath + "/output.csv", true);


  for (int i = 0; i < halfSamplerate; i++) {
    osc.setFrequency(i);
    for (int j = 0; j < halfSamplerate/(1+i); j++) {
      currentSample = fabs(filter.process(osc.genNextSample()));

      if (currentSample > highestSample) {
        highestSample = currentSample;
      }
    }
    fileWriter.write(std::to_string(highestSample) + "\n");
  }

  return 0;
}
