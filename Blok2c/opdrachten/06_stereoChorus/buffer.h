//
// Created by cashu on 15/02/2025.
//

#ifndef Buffer_H
#define Buffer_H

class Buffer {
public:
  Buffer( int bufferSize);
  ~Buffer();

  void setBufferSize(int bufferSize);
  int getBufferSize();


private:
  float* buffer;
  int bufferSize;

};

#endif //Buffer_H
