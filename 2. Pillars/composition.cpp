#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player
{
private:
  string name;
  int score;

public:
  Player(string playerName) : name(playerName), score(0) {}

  void bat()
  {
    int run = rand() % 7; // Random runs from 0 to 6
    score += run;
    cout << name << " scored: " << run << " runs" << endl;
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

class CricketTeam
{
private:
  vector<Player> players; // Composition: Team "has" Players

public:
  CricketTeam(const vector<string> &playerNames)
  {
    for (const auto &name : playerNames)
    {
      players.emplace_back(name); // Creating Player objects within CricketTeam
    }
  }

  void teamPlay()
  {
    for (auto &player : players)
    {
      player.bat();
    }
  }

  void displayScores() const
  {
    cout << "\n--- Team Scoreboard ---\n";
    for (const auto &player : players)
    {
      cout << player.getName() << ": " << player.getScore() << " runs\n";
    }
  }
};

int main()
{
  vector<string> playerNames = {"Player 1", "Player 2", "Player 3"};
  CricketTeam team(playerNames);

  team.teamPlay();
  team.displayScores();

  return 0;
}
