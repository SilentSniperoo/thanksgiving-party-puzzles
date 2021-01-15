#include "input.h"
#include <iostream>

bool IsNumber(char c) {
  return c >= '0' && c <= '9';
}
bool IsUppercase(char c) {
  return c >= 'A' && c <= 'Z';
}
bool IsLowercase(char c) {
  return c >= 'a' && c <= 'z';
}
bool IsLetter(char c) {
  return IsUppercase(c) || IsLowercase(c);
}
namespace CharSets
{
  const char* Brackets = "()[]{}<>";
  const char* Punctuation = ",.;:!?`'\"";
  const char* MathSymbol = "-=+*/^";
  const char* OtherSymbol = "&%$#@~_|\\";
  const char* WhiteSpace = " \t\n";
  const char* AllTextSymbols[] = {
    Brackets,
    Punctuation,
    MathSymbol,
    OtherSymbol,
    WhiteSpace,
  };
}
bool IsInCharSet(char c, const char* set) {
  while (*set != 0)
    if (*(set++) == c) return true;
  return false;
}
bool IsBracket(char c) {
  return IsInCharSet(c, CharSets::Brackets);
}
bool IsPunctuation(char c) {
  return IsInCharSet(c, CharSets::Punctuation);
}
bool IsMathSymbol(char c) {
  return IsInCharSet(c, CharSets::MathSymbol);
}
bool IsOtherSymbol(char c) {
  return IsInCharSet(c, CharSets::OtherSymbol);
}
bool IsWhiteSpace(char c) {
  return IsInCharSet(c, CharSets::WhiteSpace);
}
bool IsTextSymbol(char c) {
  for (int i = 0; i < 5; ++i)
    if (IsInCharSet(c, CharSets::AllTextSymbols[i]))
      return true;
  return false;
}
bool IsText(char c) {
  return
    IsNumber(c) ||
    IsLetter(c) ||
    IsTextSymbol(c);
}

std::string ReadLine()
{
  std::string result;
  char c;
  while ((c = std::cin.get()) != '\n')
    if (IsText(c)) result += c;
  return result;
}

std::string ToUppercase(const std::string& Input)
{
  std::string result(Input);
  for (char& c : result)
    if (IsLowercase(c)) c += 'A' - 'a';
  return result;
}
std::string ToLowercase(const std::string& Input)
{
  std::string result(Input);
  for (char& c : result)
    if (IsUppercase(c)) c += 'a' - 'A';
  return result;
}
void ToUppercase(std::string& Input)
{
  for (char& c : Input)
    if (IsLowercase(c)) c += 'A' - 'a';
}
void ToLowercase(std::string& Input)
{
  for (char& c : Input)
    if (IsUppercase(c)) c += 'a' - 'A';
}

bool Equal(
  const std::string& a,
  const std::string& b,
  bool CaseMatters)
{
  if (CaseMatters) return a == b;
  return ToUppercase(a) == ToUppercase(b);
}

bool CheckFor(
  const strings& Desired,
  bool CaseMatters)
{
  return CheckFor(Desired, ReadLine(), CaseMatters);
}
bool CheckFor(
  const strings& Desired,
  const std::string& Source,
  bool CaseMatters)
{
  for (const std::string & s : Desired)
    if (Equal(s, Source, CaseMatters))
      return true;
  return false;
}
bool CheckFor(
  const std::string& Desired,
  bool CaseMatters)
{
  return CheckFor(Desired, ReadLine(), CaseMatters);
}
bool CheckFor(
  const std::string& Desired,
  const std::string& Source,
  bool CaseMatters)
{
  return Equal(Desired, Source, CaseMatters);
}
