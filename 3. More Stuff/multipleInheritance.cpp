#include <iostream>
#include <string>
using namespace std;

class Batsman
{
public:
  void bat()
  {
    cout << "Batsman is batting." << endl;
  }
};

class Bowler
{
public:
  void bowl()
  {
    cout << "Bowler is bowling." << endl;
  }
};

// AllRounder inherits from both Batsman and Bowler
class AllRounder : public Batsman, public Bowler
{
public:
  void showSkills()
  {
    bat();  // From Batsman
    bowl(); // From Bowler
  }
};

int main()
{
  AllRounder player;
  player.showSkills();

  return 0;
}
