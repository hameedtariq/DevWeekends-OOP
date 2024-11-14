#include <iostream>
using namespace std;

class Player
{
protected:
  string name;
  int score;

public:
  Player(string playerName) : name(playerName), score(0) {}

  // Function to score a single run
  void scoreRun()
  {
    score += 1;
    cout << name << " scored 1 run." << endl;
  }

  // Overloaded function to score multiple runs
  void scoreRun(int runs)
  {
    score += runs;
    cout << name << " scored " << runs << " runs." << endl;
  }

  // Display the current score
  void displayScore() const
  {
    cout << name << " total score: " << score << " runs" << endl;
  }
};

class Batsman : public Player
{
public:
  Batsman(string playername) : Player(playername) {}
  void displayScore() const
  {
    cout << name << " (batsman) total score: " << score << " runs" << endl;
  }
  void scoreRun()
  {
    score += 1;
    cout << name << " scored 1 run." << endl;
  }
};

main()
{
  Player player("Player 1");

  player.scoreRun();  // Calls scoreRun() with no arguments
  player.scoreRun(4); // Calls scoreRun(int runs) with an argument
  player.displayScore();

  Batsman player2("Player 2"); // Calls batsman's displayScore method
  player2.displayScore();

  // player2.scoreRun(10); // method shadowing

  return 0;
}
