#include <iostream>
#include <string>
using namespace std;

// Global variables
int player1Score = 0;
int player2Score = 0;
string player1Name = "Player 1";
string player2Name = "Player 2";

// Functions to manage gameplay
void displayScore()
{
  cout << player1Name << ": " << player1Score << " runs" << endl;
  cout << player2Name << ": " << player2Score << " runs" << endl;
}

void bat(int &score)
{
  int run = rand() % 7; // Random runs from 0 to 6
  score += run;
  cout << "Run scored: " << run << endl;
}

void startGame()
{
  cout << "Starting the game...\n";
  bat(player1Score);
  bat(player2Score);
  displayScore();
}

int main()
{
  startGame();
  return 0;
}
