//
// Created by cashu on 15/05/2025.
//
#pragma once

class Queue {
public:
  Queue();
  ~Queue();

  void setBufferSize(int bufferSize);
  int getBufferSize();

  //return the popped value? probably not
  void push(double value);

  double read(int index);

private:

  double* buffer = nullptr;
  int bufferSize;

};
