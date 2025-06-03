#include <iostream>
#include "triangle.h"
#include "sine.h"
#include "saw.h"
#include <audioToFile.h>
#include "diracDelta.h"
#include <complex>
#include "all-passFilter.h"
#include "filter.h"
#include "combFilter.h"
#include "low-passFilter.h"


int main() {

  int samplerate = 48000;
  int halfSamplerate = (int)(0.5f*samplerate);

  Sine osc{0};
  osc.prepare(samplerate);

  LPF filter{0.89f};


  const std::string sourcePath = SOURCE_DIR;
  WriteToFile fileWriter(sourcePath + "/output.csv", true);


  for (int i = 0; i < halfSamplerate; i++) {
    osc.setFrequency((float)i);
    double highestSample = 0.0f;

    for (int j = 0; j < (500*(halfSamplerate/(1 + i))); j++) {
      double currentSample = fabs(filter.process(osc.genNextSample()));

      if (currentSample > highestSample) {
        highestSample = currentSample;
      }
    }
    fileWriter.write(std::to_string(highestSample) + "\n");
  }

  return 0;
}
