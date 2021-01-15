#ifndef OUTPUT_H
#define OUTPUT_H

#include <iostream>
#include <string>
#include <map>

void Clear();

void WriteLine(std::string line, int delay = 0);

class TimedCout
{
public:
  // Delay default in milliseconds
  int delay = 25;
  // Delay overrides in milliseconds for specific characters
  void AddDelayFor(char c, int deltaDelay);
  void SetDelayFor(char c, int delay);
private:
  std::map<char, int> delay_punctuators;
public:
  
  // STL strings
  TimedCout& operator<<(const std::string other);
  // Null terminated strings
  TimedCout& operator<<(const char* other);
  // Single characters (no "std::to_string(char)" function)
  TimedCout& operator<<(const char& other);
  
  // Basic types
  template<typename T>
  TimedCout& operator<<(const T& other)
  {
    return *this << std::to_string(other);
  }
  // Manipulators
  TimedCout& operator<<(std::ostream& (*other)(std::ostream&))
  {
    other(std::cout); return *this;
  }
} extern tcout;

#endif // OUTPUT_H
