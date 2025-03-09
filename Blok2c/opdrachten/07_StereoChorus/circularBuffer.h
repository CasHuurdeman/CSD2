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

  void incrementHead(int& head);
  void setDelay();
  float read();
  void write(float sample);
  void tick();

  float* buffer= nullptr;


private:
  int bufferSize;

  int readHead;
  int writeHead;
  float numSamplesDelay;

};
