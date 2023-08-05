#include "Player.h"

// static attribute
int Player::num_players{0}; // best place is to initialize static variables is here, in .cpp file (it should only be done once)
// No need to specify static again here, as it is already declared in player.h file
// best place is to assign it here, in .cpp file (it should only be done once)
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    ++num_players;
}
Player::Player(const Player &source) : Player{source.name, source.health, source.xp}//as we are delegating the initializationi list, the main constructor will be called and static variable "num_players" will be incremented, everytime the object is copied 
{
}
Player::~Player()
{
    --num_players;
}

// static method
int Player::get_num_players() // as in our class declaration in player.h file, we have declared this method as static, hence we dont need to specify static again here in implementation part
{
    return num_players;
}
