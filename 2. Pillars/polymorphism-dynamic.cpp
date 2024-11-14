#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  What is polymorphism ?
    write one function and have it perform different behaviors based on the type of object
  Types:
  1. Static: Overloading and overriding
  2. Dynamic: Runtime Polymorphism
*/

class Player
{
protected:
  string name;
  int score;

public:
  Player(string playerName) : name(playerName), score(0) {}

  virtual void bat()
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

class Batsman : public Player
{
public:
  Batsman(string playerName) : Player(playerName) {}

  void bat() override
  {
    int run = (rand() % 7) + 1; // Batsman has a higher chance to score
    this->score += run;
    cout << getName() << " (Batsman) scored: " << run << " runs\n";
  }
};

class Bowler : public Player
{
public:
  Bowler(string playerName) : Player(playerName) {}

  void bowl()
  {
    cout << getName() << " (Bowler) is bowling...\n";
  }
};

// Polymorphism
int main()
{
  vector<Player *> players;
  players.push_back(new Batsman("Player 1"));
  players.push_back(new Bowler("Player 2"));

  for (Player *player : players)
  {
    player->bat(); // Calls Batsman::bat() if the player is a Batsman, else Player::bat()
  }

  // Clean up
  for (Player *player : players)
  {
    delete player;
  }
  return 0;
}
