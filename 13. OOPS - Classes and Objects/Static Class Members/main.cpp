#include <iostream>
#include "Player.h"

using namespace std;

void displayActivePlayer()
{
    cout << "Active Players(total player objects live): " << Player::get_num_players() << endl;
}

int main()
{
    displayActivePlayer();
    Player p1;
    Player p2;
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