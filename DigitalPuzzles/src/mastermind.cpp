#include "mastermind.h"
#include "input.h"
#include "output.h"
#include "random.h"
#include "answers.h"
#include "cheats.h"

static std::string hint;
static std::string reward;
static std::string answer;
static const int CodeSize = 4;

// In order to remove items, we just mark them with an unused value
static const char ColorInvalid = -1;
static const char Colors[] = "rgbyop";
// Size of entire array / size of array element - extra invisible NULL (0)
static const int ColorCount = sizeof(Colors) / sizeof(*Colors) - 1;

void NotExactMatch(std::string guess)
{
  // Copy the correct answer
  std::string copy(answer);

  // Count the number of exactly matching characters
  int exactMatches = 0;
  for (int i = 0; i < CodeSize; ++i)
  {
    // If it isn't a match, skip it
    if (guess[i] != copy[i]) continue;

    // Record the match and remove the item
    // (since we don't want to use it twice)
    ++exactMatches;
    guess[i] = copy[i] = ColorInvalid;
  }

  // Count the number of color matches
  int colorMatches = 0;
  for (int i = 0; i < CodeSize; ++i)
  {
    // If the character is already finished, ignore it
    if (guess[i] == ColorInvalid) continue;

    // For each guess character (i) loop through each copy character (j)
    for (int j = 0; j < CodeSize; ++j)
    {
      // If it isn't a match, skip it
      if (guess[i] != copy[j]) continue;

      // Record the match and remove the item
      // (since we don't want to use it twice)
      ++colorMatches;
      // In order to remove the item, we just mark it
      // with an unused value
      guess[i] = copy[j] = ColorInvalid;

      // Stop looking for this guess character (i)
      break;
    }
  }

  // Print the results
  tcout << "You got " << exactMatches
    << " correct colors in the correct spots." << std::endl;
  tcout << "You got " << colorMatches
    << " correct colors in the wrong spots." << std::endl;
}

bool ValidateInput(const std::string& input)
{
  // Assume valid until disproven
  bool result = true;

  // Check value of characters
  for (const char& c : input)
  {
    if (!IsInCharSet(c, Colors))
    {
      // Tell value of characters
      tcout << "Oops! You input an invalid character: ";
      tcout << "'" << c << "'" << std::endl;
      result = false;
    }
  }
  // Tell possible characters
  if (result == false)
  {
    tcout << "Possible colors: 'r', 'g', 'b', 'y', 'o', and 'p'" << std::endl;
    tcout << "(red, green, blue, yellow, orange, and purple)." << std::endl;
  }

  // Check number of characters
  int size = input.size();
  if (size != CodeSize)
  {
    if (input.size() > CodeSize)
      tcout << "Oops! You entered too many characters." << std::endl;
    if (input.size() < CodeSize)
      tcout << "Oops! You didn't enter enough characters." << std::endl;

    // Tell number of characters
    tcout << "You entered " << size << " characters instead of "
      << CodeSize << "." << std::endl;
    result = false;
  }
  return result;
}

std::string MakeRandomAnswer()
{
  std::string result;
  for (int i = 0; i < CodeSize; ++i)
    result.push_back(Colors[ZeroToNMinus1(ColorCount)]);
  return result;
}

std::string GetCode()
{
  tcout << "Guess the order of the " << CodeSize
    << " colors (eg. \"" << MakeRandomAnswer() << "\"): ";
  return ReadLine();
}

void StartMastermind()
{
  hint = "Try using one color at a time.";
  reward = "a new clue: \"color\"";

  // Pick a random answer
  answer = MakeRandomAnswer();

  // Print instructions
  tcout << "Guess the color code." << std::endl;
  tcout << "Code length: " << CodeSize << std::endl;
  tcout << "Possible colors: 'r', 'g', 'b', 'y', 'o', and 'p'" << std::endl;
  tcout << "(red, green, blue, yellow, orange, and purple)." << std::endl << std::endl;
}

GameResult SolveMastermind()
{
  GameResult result = GameResult::Failure;

  // Get the input
  std::string input;
  do {
    input = GetCode();

    // Parse the input
    if (CheckForCheats(input, hint, answer, reward, result)) return result;
  } while (!ValidateInput(input));

  // We didn't find exact match so print how close the player was
  NotExactMatch(input);
  tcout << "\"" << input << "\" is incorrect! Try again.\n" << std::endl;
  return result;
}
