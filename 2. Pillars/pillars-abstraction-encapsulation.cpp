#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  1. Abstraction
  2. Encapsulation
  3. Inheritance
  4. Polymorphism

--------
  Composition
  Aggregation

*/

// Encapsulation
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

  void setName(string name)
  {
    this->name = name;
  }
};

int main()
{
  Player p1 = "Hameed";
  p1.bat(); // Abstraction
  vector<Player> players;
  players.push_back(p1);
  return 0;
}
