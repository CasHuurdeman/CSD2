#include "circBuffer.h"


CircBuffer::CircBuffer(uint size, uint numSamplesDelay)
{
  std::cout << "CircBuffer::CircBuffer()" << std::endl;

  m_size = size;
  m_numSamplesDelay = numSamplesDelay;
  allocateBuffer();
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
  if(head >= m_size){
    head -= m_size;
  }
  else { head += 1; }
}


void CircBuffer::tick(){
  setDelay();
  incrementHead(m_wHead);
  incrementHead(m_rHead);
}
void CircBuffer::allocateBuffer()
{
  // allocate buffer and set all samples to 0
  m_buffer = (float*)malloc(m_size * sizeof(float));
  memset(m_buffer, 0, m_size * sizeof(float));
}

void CircBuffer::releaseBuffer()
{
  // free data allocated with memset
  free(m_buffer);
}

CircBuffer::~CircBuffer()
{
  std::cout << "CircBuffer::~CircBuffer()" << std::endl;
  // TODO - release the dynamic allocated array
  releaseBuffer();
}
