#include "output.h"
#include <iostream>
#include <thread>
#include <chrono>

TimedCout tcout;

void Clear()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void WriteLine(std::string line, int delay)
{
  int old = tcout.delay;
  tcout.delay = delay;
  tcout << line;
  tcout.delay = old;
  std::cout << std::endl;
}

void TimedCout::AddDelayFor(char c, int deltaDelay)
{
  delay_punctuators[c] = delay + deltaDelay;
}
void TimedCout::SetDelayFor(char c, int totalDelay)
{
  delay_punctuators[c] = totalDelay;
}

TimedCout& TimedCout::operator<<(const std::string other)
{
  for (const char& c : other)
  {
    std::cout << c << std::flush;
    int characterDelay = delay;
    if (delay_punctuators.find(c) != delay_punctuators.end())
      characterDelay = delay_punctuators[c];
    std::this_thread::sleep_for(std::chrono::milliseconds(characterDelay));
  }
  return *this;
}
TimedCout& TimedCout::operator<<(const char* other)
{
  return *this << std::string(other);
}
TimedCout & TimedCout::operator<<(const char & other)
{
  return *this << std::string(1, other);
}
