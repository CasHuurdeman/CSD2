#include "circBuffer.h"


CircBuffer::CircBuffer(uint size, uint numSamplesDelay)
{
  std::cout << "CircBuffer::CircBuffer()" << std::endl;

  m_buffer.resize(size);
  m_numSamplesDelay = numSamplesDelay;
}


void CircBuffer::write(float sample){
  m_buffer[m_wHead] = sample;
}

float CircBuffer::read(){
  return m_buffer[m_rHead];
}

void CircBuffer::setDelay(){
  m_rHead = m_wHead - m_numSamplesDelay;
}

void CircBuffer::incrementHead(int& head){
  if(head >= m_buffer.size()){
    head -= m_buffer.size();
  }
  else { head += 1; }
}


void CircBuffer::tick(){
  setDelay();
  incrementHead(m_wHead);
  incrementHead(m_rHead);
}


CircBuffer::~CircBuffer()
{
  std::cout << "CircBuffer::~CircBuffer()" << std::endl;
  // TODO - release the dynamic allocated array
}
