#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

bool IsNumber(char c);
bool IsUppercase(char c);
bool IsLowercase(char c);
bool IsLetter(char c);
bool IsInCharSet(char c, const char* set);
bool IsBracket(char c);
bool IsPunctuation(char c);
bool IsMathSymbol(char c);
bool IsOtherSymbol(char c);
bool IsTextSymbol(char c);
bool IsText(char c);

std::string ReadLine();

void ToUppercase(std::string& Input);
std::string ToUppercase(const std::string& Input);
void ToLowercase(std::string& Input);
std::string ToLowercase(const std::string& Input);

bool Equal(
  const std::string& a,
  const std::string& b,
  bool CaseMatters = true);

typedef std::vector<std::string> strings;

bool CheckFor(
  const strings& Desired,
  bool CaseMatters = true);
bool CheckFor(
  const strings& Desired,
  const std::string& Source,
  bool CaseMatters = true);
bool CheckFor(
  const std::string& Desired,
  bool CaseMatters = true);
bool CheckFor(
  const std::string& Desired,
  const std::string& Source,
  bool CaseMatters = true);

#endif // INPUT_H
