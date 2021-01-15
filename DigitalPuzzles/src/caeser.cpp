#include "caeser.h"
#include "input.h"
#include "output.h"
#include "random.h"
#include "answers.h"
#include "cheats.h"
#include "math.h"

static std::string hint;
static std::string reward;
static std::string question;
static std::string answer;
static std::string cipher;
static int key;

char Caeser(int Offset, char c)
{
  if (!IsLetter(c)) return c;
  if (IsUppercase(c))
    return Wrap(c + Offset, 'A', 'Z');
  return Wrap(c + Offset, 'a', 'z');
}
void Caeser(int Offset, std::string& Input)
{
  for (char & c : Input) c = Caeser(Offset, c);
}

void StartCaeser()
{
  hint = "Try giving each letter of the alphabet a number.";
  reward = "a new clue: \"humor\"";

  // Pick a random answer
  //answer = GetRandomAnswer();
  std::pair<std::string, std::string> temp = GetRandomQuestionAnswerPair();
  question = temp.first;
  answer = temp.second;

  // Pick a random offset
  key = Probability(0.5)
    ? key = RangeInclusive(3, 10)
    : key = RangeInclusive(-3, -10);

  // Create the cipher answer
  cipher = answer;
  Caeser(key, cipher);

  // Print instructions
  //tcout << "Decode the following message." << std::endl << std::endl;
  tcout << question << std::endl << std::endl;
}

GameResult SolveCaeser()
{
  GameResult result = GameResult::Failure;

  // Get the input
  tcout << cipher << std::endl;
  std::string input(ReadLine());

  // Parse the input
  if (CheckForCheats(input, hint, answer, reward, result)) return result;

  // We didn't find exact match so print how close the player was
  Caeser(key, input);
  tcout << "\"" << input << "\" is incorrect! Try again.\n" << std::endl;
  tcout << question << std::endl << std::endl;
  return result;
}
