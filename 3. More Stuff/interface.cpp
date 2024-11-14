#include <iostream>
#include <string>
using namespace std;

/*
  Use it when you want to define a strict contract that multiple unrelated classes must adhere to,
  without any common implementation.
*/

class IScorer
{ // Interface-like class
public:
  virtual void scoreRuns(int runs) = 0;
  virtual void displayScore() const = 0;
  virtual ~IScorer() {}
};

class Batsman : public IScorer
{
private:
  string name;
  int score;

public:
  Batsman(string playerName) : name(playerName), score(0) {}

  void scoreRuns(int runs) override
  {
    score += runs;
    cout << name << " scored " << runs << " runs." << endl;
  }

  void displayScore() const override
  {
    cout << name << " total score: " << score << " runs" << endl;
  }

  void bat() {}
};

int main()
{
  IScorer *player = new Batsman("Virat Kohli");

  player->scoreRuns(4);   // Calls scoreRuns() from Batsman
  player->displayScore(); // Calls displayScore() from Batsman

  // player->bat();

  delete player;
  return 0;
}
