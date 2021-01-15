#include "random.h"

#include <random> // srand
#include <ctime> // time

unsigned Seed;

void InitializeRandom()
{
  SetSeed(static_cast<unsigned>(time(nullptr)));
}
unsigned GetSeed()
{
  return Seed;
}
void SetSeed(unsigned seed)
{
  Seed = seed;
  srand(Seed);
}

unsigned ZeroToNMinus1(unsigned N) {
  // Avoid division by zero
  return N < 1 ? 0 : rand() % N;
}
int RangeInclusive(int a, int b) {
  // Value wrapped in the gap size added to the position of the gap
  int gap = a - b;
  return gap > 0
    ? ZeroToNMinus1(1 + gap) + b
    : ZeroToNMinus1(1 - gap) + a;
}
int Probability(float outOf1) {
  // If odds are small, then the fraction will probably not be smaller
  return (rand() / static_cast<float>(RAND_MAX)) < outOf1;
}
int Probability(double outOf1) {
  // If odds are small, then the fraction will probably not be smaller
  return (rand() / static_cast<double>(RAND_MAX)) < outOf1;
}
