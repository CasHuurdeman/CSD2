#include <iostream>
#include "sine.h"
#include "audioToFile"


int main() {
  // create sine wave
  Sine sine(1);
  std::cout << "Sine frequency: " << sine.getFrequency() << "\n";

  const std::string sourcePath = SOURCE_DIR;
  AudioToFile audioToFile (sourcePath + "/output.csv");
  audioToFile.write (audioSource);

  // end of program
  return 0;
}
