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
    int run = rand() % 7;
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

class CricketTeam
{
private:
  string teamName;
  vector<Player> players;

public:
  CricketTeam(string name, const vector<string> &playerNames) : teamName(name)
  {
    for (const auto &playerName : playerNames)
    {
      players.emplace_back(playerName);
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
    cout << "\n--- " << teamName << " Scoreboard ---\n";
    for (const auto &player : players)
    {
      cout << player.getName() << ": " << player.getScore() << " runs\n";
    }
  }

  string getTeamName() const
  {
    return teamName;
  }
};

class Stadium
{
private:
  vector<CricketTeam *> teams; // Aggregation: Stadium "has" Teams, but doesn't own them

public:
  void addTeam(CricketTeam *team)
  {
    teams.push_back(team); // Adding a reference to existing CricketTeam objects
  }

  void startMatch()
  {
    cout << "Starting the match in the stadium...\n";
    for (auto *team : teams)
    {
      team->teamPlay();
      team->displayScores();
    }
  }
};

int main()
{
  // Create teams independently of the stadium
  CricketTeam team1("Team A", {"Player 1", "Player 2"});
  CricketTeam team2("Team B", {"Player 3", "Player 4"});

  Stadium stadium;
  stadium.addTeam(&team1); // Aggregation: Stadium only holds references to teams
  stadium.addTeam(&team2);

  stadium.startMatch();

  return 0;
}
