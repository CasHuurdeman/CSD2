#include <iostream>
#include "triangle.h"
#include "sine.h"
#include "saw.h"
#include <audioToFile.h>
#include "diracDelta.h"
#include <complex>
#include "filters.h"


int main() {

  int samplerate = 48000;
  int halfSamplerate = (int)(0.5f*samplerate);

  float currentSample = 0.0f;
  float highestSample = 0.0f;

  Saw osc{0};

  SimpleLadder filter;
  filter.setCoefficient(0.9f);


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
