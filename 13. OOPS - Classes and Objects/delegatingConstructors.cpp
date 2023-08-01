#include <iostream>
#include <string>
using namespace std;

class Game
{
private:
  string name;
  int players;
  double time;

public:
  Game();
  Game(string);
  Game(string, int, double);
};
// delegating constructor (why need it? - because we dont want to have duplicate codes in our program, delegate the task to others as much as possible, good practice)
Game::Game() : Game{"Chess", 0, 0}
{
  cout << "No-args constructor" << endl;
}; // delegating the constructor initilization to
   // 3-args constructor
Game::Game(string name_val) : Game{name_val, 0, 0}
{
  cout << "1-args constructor" << endl;
}; // delegating the constructor initilization to
   // 3-args constructor
Game::Game(string name_val, int no_of_players, double total_time)
    : name{name_val}, players{no_of_players}, time{total_time}
{
  cout << "3-args constructor" << endl;
}; // every constructor is delegating the task here
int main()
{
  Game chess;
  Game basketball("basketball");
  Game tableTennis("tableTennis", 2, 100);
  return 0;
}
