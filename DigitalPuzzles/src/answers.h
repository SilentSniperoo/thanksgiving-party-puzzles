#ifndef ANSWERS_H
#define ANSWERS_H

#include "input.h"

enum class GameResult
{
  Restart = -1,
  Failure = false,
  Success = true
};

void InitializeAnswerPool();
std::string GetRandomAnswer(); // Uses deck random
std::pair<std::string, std::string> GetRandomQuestionAnswerPair(); // Uses deck random

void PrintReward(const std::string& reward);

#endif // ANSWERS_H
