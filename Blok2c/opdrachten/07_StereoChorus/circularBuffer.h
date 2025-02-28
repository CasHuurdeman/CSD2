//
// Created by cashu on 15/02/2025.
//

#ifndef Buffer_H
#define Buffer_H

class CircularBuffer {
public:
  CircularBuffer() = default;
  CircularBuffer(int bufferSize, int numSamplesDelay);
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
  int numSamplesDelay;

};

#endif //Buffer_H
