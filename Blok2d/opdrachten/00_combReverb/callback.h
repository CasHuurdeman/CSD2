#ifndef CALLBACK_H
#define CALLBACK_H

#include <audiocomponent.h>


class CustomCallback : public AudioCallback {
public:
  CustomCallback (double sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

private:
  double samplerate = 44100;


};

#endif //CALLBACK_H
