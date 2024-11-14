#include <iostream>
#include <string>
using namespace std;

/*
  Used when you want to share some common functionality accross multiple classes
*/

class Player
{
protected:
  string name;

public:
  Player(string playerName) : name(playerName) {}

  virtual void play() = 0; // Pure virtual function, making this class abstract

  void displayPlayer()
  {
    cout << "Player: " << name << endl;
  }

  virtual ~Player() {} // Virtual destructor for cleanup
};

class Batsman : public Player
{
public:
  Batsman(string playerName) : Player(playerName) {}

  void play() override
  {
    cout << name << " (Batsman) is batting." << endl;
    // Additional batting behavior can be implemented here
  }
};

class Bowler : public Player
{
public:
  Bowler(string playerName) : Player(playerName) {}

  void play() override
  {
    cout << name << " (Bowler) is bowling." << endl;
    // Additional bowling behavior can be implemented here
  }
};

int main()
{
  Player *player1 = new Batsman("Virat Kohli");
  Player *player2 = new Bowler("Jasprit Bumrah");

  player1->play(); // Calls Batsman's play() function
  player2->play(); // Calls Bowler's play() function

  delete player1;
  delete player2;

  return 0;
}
