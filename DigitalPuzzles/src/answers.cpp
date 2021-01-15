#include "answers.h"
#include "output.h"

static strings answers;
static std::vector<std::pair<std::string, std::string>> question_answer_pairs;
static unsigned answers_remaining = 0;

void InitializeAnswerPool()
{
  //////////////////////////////////////////////////////////////////////////////
  // Initialize cheats
  answers.push_back("Happy Thanksgiving!");
  answers.push_back("I'm stuffed with stuffing.");
  answers.push_back("I like turkey AND chicken.");
  question_answer_pairs.push_back(
  { "Which side of the turkey has the most feathers?", "The outside!" });
  question_answer_pairs.push_back(
  { "When the Pilgrims landed, where did they stand?", "On their feet!" });
  question_answer_pairs.push_back(
  { "What's the best thing to put into a pumpkin pie?", "Your teeth!" });
  question_answer_pairs.push_back(
  { "What kind of music did the Pilgrims listen to?", "Plymouth Rock!" });
  //////////////////////////////////////////////////////////////////////////////
}

std::string GetRandomAnswer()
{
  if (answers_remaining < 1)
    if ((answers_remaining = answers.size()) < 1)
      return std::string();

  unsigned index = rand() % answers_remaining--;
  std::string result(answers[index]);

  answers[index] = answers[answers_remaining];
  answers[answers_remaining] = result;

  return result;
}

std::pair<std::string, std::string> GetRandomQuestionAnswerPair()
{
  if (answers_remaining < 1)
    if ((answers_remaining = answers.size()) < 1)
      return std::pair<std::string, std::string>();

  unsigned index = rand() % answers_remaining--;
  std::pair<std::string, std::string> result(question_answer_pairs[index]);

  question_answer_pairs[index] = question_answer_pairs[answers_remaining];
  question_answer_pairs[answers_remaining] = result;

  return result;
}

void PrintReward(const std::string & reward)
{
  tcout << "\aSuccess! Your reward is " << reward << std::endl;
}
