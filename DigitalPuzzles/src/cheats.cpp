#include "cheats.h"
#include "output.h"
#include "answers.h"

static strings cheat_enable;
static strings cheat_quit;
static strings cheat_hint;
static strings cheat_answer;
static strings cheat_restart;
static strings cheat_win;

void InitializeCheats()
{
  //////////////////////////////////////////////////////////////////////////////
  // Initialize cheats
  cheat_enable.push_back(":enable");
  cheat_enable.push_back(":e");

  cheat_quit.push_back(":quit");
  cheat_quit.push_back(":q");

  cheat_hint.push_back(":hint");
  cheat_hint.push_back(":help");
  cheat_hint.push_back(":h");

  cheat_answer.push_back(":answer");
  cheat_answer.push_back(":a");

  cheat_restart.push_back(":restart");
  cheat_restart.push_back(":reset");
  cheat_restart.push_back(":r");

  cheat_win.push_back(":win");
  cheat_win.push_back(":w");
  //////////////////////////////////////////////////////////////////////////////
}

bool CheckForCheats(
  const std::string & input,
  const std::string& hint,
  const std::string& answer,
  const std::string& reward,
  GameResult & result)
{
  if (CheckFor(cheat_quit, input)) exit(0);
  if (CheckFor(cheat_hint, input))
  {
    tcout << hint << std::endl;
    result = GameResult::Failure;
    return true;
  }
  if (CheckFor(cheat_answer, input))
  {
    tcout << answer << std::endl;
    result = GameResult::Failure;
    return true;
  }
  if (CheckFor(cheat_restart, input))
  {
    result = GameResult::Restart;
    return true;
  }
  if (CheckFor(cheat_win, input) || CheckFor(answer, input, false))
  {
    PrintReward(reward);
    result = GameResult::Success;
    return true;
  }
  return false;
}
