#ifndef RANDOM_H
#define RANDOM_H

// Set the seed to "time(nullptr)"
void InitializeRandom();
unsigned GetSeed();
void SetSeed(unsigned seed);

unsigned ZeroToNMinus1(unsigned N);
int RangeInclusive(int a, int b);
int Probability(float outOf1);
int Probability(double outOf1);

#endif // RANDOM_H
