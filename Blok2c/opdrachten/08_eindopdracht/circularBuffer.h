//
// Created by cashu on 15/02/2025.
//
#pragma once

class CircularBuffer {
public:
  CircularBuffer() = default;
  CircularBuffer(int bufferSize, float numSamplesDelay);
  ~CircularBuffer();

  void setBufferSize(int bufferSize);
  int getBufferSize();
  void setNumSamplesDelay(float numSamplesDelay);
  int getNumSamplesDelay();

  void updateDelay();
  void wrap(int &head);

  float read();
  void write(float sample);



private:
  float* buffer= nullptr;
  int bufferSize;

  int readHead = 0;
  int writeHead = 0;
  float numSamplesDelay = 0;

};
