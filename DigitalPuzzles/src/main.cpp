#include "input.h"
#include "output.h"
#include "random.h"
#include "answers.h"
#include "cheats.h"

#include "caeser.h"
#include "mastermind.h"

enum class Game
{
  Caeser,
  Mastermind,
  Spellchecker,

  COUNT
};
Game operator ++(Game& game)
{
  switch (game) {
  case Game::Caeser: return game = Game::Mastermind;
  case Game::Mastermind: return game = Game::Spellchecker;
  case Game::Spellchecker: return game = Game::COUNT;
  }
  return game = Game::Caeser;
}
Game operator ++(Game& game, int)
{
  Game old = game;
  switch (game) {
  case Game::Caeser: return game = Game::Mastermind, old;
  case Game::Mastermind: return game = Game::Spellchecker, old;
  case Game::Spellchecker: return game = Game::Caeser, old;
  }
  return game;
}

void DoPuzzle(void (*StartFunction)(), GameResult (*SolveFunction)())
{
  // Restart loop
  GameResult result = GameResult::Failure;
  while (result != GameResult::Success)
  {
    Clear();
    StartFunction();

    // Update loop
    result = GameResult::Failure;
    while (result == GameResult::Failure)
    {
      result = SolveFunction();
    }
  }
}

int main()
{
  // Initialize random
  InitializeRandom();
  // Initialize answers
  InitializeAnswerPool();
  // Initialize cheats
  InitializeCheats();

  //////////////////////////////////////////////////////////////////////////////
  // Initialize timed cout
  tcout.delay = 25;
  tcout.AddDelayFor(' ', 25);
  tcout.AddDelayFor('\'', 50);
  tcout.AddDelayFor('\"', 75);
  tcout.AddDelayFor(',', 100);
  tcout.AddDelayFor('.', 125);
  tcout.AddDelayFor('?', 150);
  tcout.AddDelayFor('!', 175);
  tcout.AddDelayFor('\n', 200);
  //////////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////////
  // Run puzzles

  // ++game when on COUNT will be the default start
  Game game = Game::COUNT;
  do {
    // Solve a Caeser cipher (guesses are printed, ciphered with the same key)
    //DoPuzzle(StartCaeser, SolveCaeser);
    // Solve a Mastermind game (no turn limit)
    DoPuzzle(StartMastermind, SolveMastermind);

    // Check for game exit
    tcout << std::endl
      << "Press ENTER to continue." << std::endl
      << "Type QUIT to exit" << std::endl;
  } while (!CheckFor("QUIT", false));

  /*
  // ++game when on COUNT will be the default start
  Game game = Game::COUNT;
  do {
    // Advance to the next game
    ++game;

    // Find the current game to play
    if (game == Game::Caeser)
    {
      // Solve a Caeser cipher (guesses are printed, ciphered with the same key)
      DoPuzzle(StartCaeser, SolveCaeser);
    }
    else if (game == Game::Mastermind)
    {
      // Solve a Mastermind game (no turn limit)
      DoPuzzle(StartMastermind, SolveMastermind);
    }
    else if (game == Game::Spellchecker)
    {
      // Find misspellings in text and make a word with the incorrect letters
      //DoPuzzle(StartSpellchecker, SolveSpellchecker);
    }
    //else if (game == Game::GridWords)
    //{
    //  
    //}
    else tcout << std::endl << "You finished all the puzzles!" << std::endl;

    // Check for game exit
    tcout << std::endl
      << "Press ENTER to continue." << std::endl
      << "Type QUIT to exit" << std::endl;
  } while (!CheckFor("QUIT", false));
  */
  //////////////////////////////////////////////////////////////////////////////
  
  return 0;
}
