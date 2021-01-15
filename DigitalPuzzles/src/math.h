#ifndef MATH_H
#define MATH_H

int Wrap(int i, int min, int max)
{
  i -= min;
  i %= max + 1 - min;
  if (i < 0) i += max + 1 - min;
  i += min;
  return i;
}

#endif // MATH_H
