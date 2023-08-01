#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    std::string getName() { return name; };
    Player(std::string name_val);
};
#endif