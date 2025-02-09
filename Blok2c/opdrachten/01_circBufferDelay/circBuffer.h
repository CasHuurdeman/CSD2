#pragma once

#include <iostream>
#include <vector>


class CircBuffer {

  using uint = unsigned int;
public:
  CircBuffer(uint size, uint numSamplesDelay);
  ~CircBuffer();

  void write(float sample);
  float read();
  void setDelay();

  void incrementHead(int& head);
  void tick();

  float delay();


private:

  std::vector<float> m_buffer;
  uint m_numSamplesDelay;

  int m_wHead = 0;
  int m_rHead = 0;

};