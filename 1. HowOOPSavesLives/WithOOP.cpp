#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  Class - Blueprints
  Objects - instances of those blueprints
  Terminologies: Contructor, access specifiers, methods (setters, getters, other functions), data members
*/

class Player
{
private:
  string name;

protected:
  int score;

public:
  Player(string playerName) : name(playerName), score(0) {}

  void bat()
  {
    int run = rand() % 7; // Random runs from 0 to 6
    score += run;
    cout << name << " scored: " << run << " runs\n";
  }

  int getScore() const
  {
    return score;
  }

  string getName() const
  {
    return name;
  }
};

class CricketGame
{
private:
  vector<Player> players;

public:
  CricketGame(vector<string> playerNames)
  {
    for (const auto &name : playerNames)
    {
      players.emplace_back(name);
    }
  }

  void startGame()
  {
    cout << "Starting the game...\n";
    for (auto &player : players)
    {
      player.bat();
    }
    displayScores();
  }

  void displayScores() const
  {
    cout << "\n--- Scoreboard ---\n";
    for (const auto &player : players)
    {
      cout << player.getName() << ": " << player.getScore() << " runs\n";
    }
  }
};

int main()
{
  vector<string> playerNames = {"Player 1", "Player 2"};
  CricketGame game(playerNames);
  game.startGame();
  return 0;
}
