//
// Created by cashu on 15/02/2025.
//

#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

class CircularBuffer {
public:
  CircularBuffer( int bufferSize);
  ~CircularBuffer();

  void setBufferSize(int bufferSize);
  int getBufferSize();


private:
  float* buffer;
  int bufferSize;

};

#endif //CIRCULARBUFFER_H
