#include "Player.h"
#include <iostream>

using namespace std;

void displayActivePlayer() {
  cout << "Active Players(total Player objects live): "
       << Player::get_num_players() << endl;
}

int main() {
  displayActivePlayer();
  Player p1{"p1"};
  Player p2{"p2"};
  displayActivePlayer();

  {
    Player p3;
    displayActivePlayer();
  }
  displayActivePlayer();

  Player *p4 = new Player("Aadarsh", 100, 30);
  displayActivePlayer();
  delete p4; // automatic call of destructor with deallocation
  displayActivePlayer();
  return 0;
}
