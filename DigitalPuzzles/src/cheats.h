#ifndef CHEATS_H
#define CHEATS_H

#include "input.h"

void InitializeCheats();

enum class GameResult;

// Returns true if caller should early with the result returned by reference
bool CheckForCheats(
  const std::string & input,
  const std::string& hint,
  const std::string& answer,
  const std::string& reward,
  GameResult & result);

#endif // CHEATS_H
