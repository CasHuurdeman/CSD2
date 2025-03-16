#include <iostream>
#include "triangle.h"
#include "sine.h"
#include <audioToFile.h>
#include "diracDelta.h"
#include <complex>
#include "filters.h"





class SpectrumAnalyser {
public:
  SpectrumAnalyser() {

    filter.setCoefficient(0.5);

    impulseResponseBuffer = new float[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
      impulseResponseBuffer[i] = 0;
    }
  }

  ~SpectrumAnalyser() {
    delete [] impulseResponseBuffer;
    impulseResponseBuffer = nullptr;
  }


  void impulsResponse() {
    //Working on convolution, now dirac delta response of the system
    for (int i = 0; i < bufferSize; i++) {
      impulseResponseBuffer[i] = filter.process(dirac.givePulse());
    }
  }


  float convolute(float freq) {
    impulsResponse();
    osc.setFrequency(freq);
    for (int i = 0; i < (0.5* samplerate); ) {
        i+= 100;
        convolution = osc.genNextSample() * impulseResponseBuffer[i];
        return convolution;
    }
    //impuls response convolueren met de frequenties --> piek onthouden
  }


  //FIXME
  float findHighest() {
    float x = 0.0f;
    float xHighest = 0.0f;

    for (int i = 0; i < (0.5* samplerate); i++) {
      x = fabs(convolute((float)i));

      if (x > xHighest) {
        xHighest = x;
      }
    }
    return xHighest;
  }



  float getSamplerate() {
    return samplerate;
  }


private:

  //------ INITIALISEREN -------
  int samplerate = 48000;

  Sine osc{10};
  DiracDelta dirac;
  FIRFilter filter;

  float convolution;

  //----- BUFFER AANMAKEN -----
  float* impulseResponseBuffer;
  int bufferSize = 5000;

};




int main() {

  // SpectrumAnalyser spectrumAnalyser;

  int samplerate = 48000;
  // Triangle osc{20};
  Sine osc{0};
  FIRFilter filter;
  filter.setCoefficient(0.9f);
  // filter.setA1Coefficient(0.5f);
  // filter.setA2Coefficient(0.5f);


  const std::string sourcePath = SOURCE_DIR;
  WriteToFile fileWriter(sourcePath + "/output.csv", true);


  for (int i = 0; i < (0.5f* samplerate); i++) {
    osc.setFrequency(i);

    //fabs to hack a spectrum instead of double (I know very confusing explanation)
    fileWriter.write(std::to_string(fabs(filter.process(osc.genNextSample()))) + "\n");
  }

  // for (int i = 0; i < 0.5*samplerate; i++) {
  // fileWriter.write(std::to_string(osc.genNextSample()) + "\n");
  // }

  return 0;
}

float getFrequencyResponse() {
  int samplerate = 48000;
  int halfSamplerate = (int)0.5f*samplerate;

  float currentSample = 0.0f;
  float highestSample = 0.0f;

  for (int i = 0; i < halfSamplerate; i++) {
    osc.setFrequency(i);
    for (int j = 0; j < halfSamplerate/i; j++) {
      currentSample = fabs(filter.process(osc.genNextSample()));

      if (currentSample > highestSample) {
        highestSample = currentSample;
      }
    }

    return highestSample;
  }
}