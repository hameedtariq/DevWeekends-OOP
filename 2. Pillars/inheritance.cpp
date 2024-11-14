#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  Inheritance ?
  types of access specifiers: public protected, private
  types of inheritance: public, protected, private
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

class Batsman : public Player
{
public:
  Batsman(string playerName) : Player(playerName) {}

  void bat()
  {
    int run = (rand() % 7) + 1; // Batsman has a higher chance to score
    score += run;
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

/*
| Base class | Derived Class          | Derived Class          | Derived Class          |
|            | Public Mode            | Private Mode           | Protected Mode         |
|------------|-------------------------|-------------------------|-------------------------|
| Private    | Not Inherited           | Not Inherited          | Not Inherited          |
| Protected  | Protected               | Private                | Protected              |
| Public     | Public                  | Private                | Protected              |
*/
