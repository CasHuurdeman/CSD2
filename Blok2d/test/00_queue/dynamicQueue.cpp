//
// Created by cashu on 15/05/2025.
//

#include "dynamicQueue.h"

Queue::Queue(bufferSize){
  std::cout << "Queue - constructor"

  this->bufferSize = bufferSize;
  buffer = new double[bufferSize];
  for (int i = 0; i < bufferSize; i++) {
    buffer[i] = 0;
  }

}

~Queue::Queue(){
  std::cout << "Queue - destructor"
  delete [] buffer;
  buffer = nullptr;
}

void Queue::push(double value){
  for()
}

double Queue::read(int index){

}

void Queue::setBufferSize(int bufferSize){
  this->bufferSize = bufferSize;

  //Delete old buffer
  if (buffer != nullptr) {
    delete [] buffer;
    buffer = nullptr;
  }

  //Set new buffer with new buffersize
  buffer = new double[bufferSize];
  for (int i = 0; i < bufferSize; i++) {
    buffer[i] = 0;
  }
}

int Queue::getBufferSize(){return bufferSize;}