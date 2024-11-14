/*
      Player
     /      \
  Batsman   Bowler
     \       /
     AllRounder
*/

/*
  Solution:
    Virtual Inheritance
    -> inherits Player class only once.

*/

#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
  Player()
  {
    cout << "Player constructor called." << endl;
  }
  void play()
  {
    cout << "Player is playing cricket." << endl;
  }
};

// Use virtual inheritance to avoid the diamond problem
class Batsman : virtual public Player
{
public:
  void bat()
  {
    cout << "Batsman is batting." << endl;
  }
};

class Bowler : virtual public Player
{
public:
  void bowl()
  {
    cout << "Bowler is bowling." << endl;
  }
};

class AllRounder : public Batsman, public Bowler
{
public:
  void showSkills()
  {
    bat();  // From Batsman
    bowl(); // From Bowler
    play(); // From Player, no ambiguity due to virtual inheritance
  }
};

int main()
{
  AllRounder player;
  player.showSkills();

  return 0;
}
