#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
private:
    // for tracking total live Player objects present
    static int num_players; // statis is specific to class, objects cannot access these variables
    // NOTE: static varibles cannot be initialized directly here
    std::string name;
    int health;
    int xp;

public:
    std::string getName() { return name; };
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    // Copy Constructor
    Player(const Player &source);
    // Destructor
    ~Player();
    static int get_num_players(); // methods defined with static can only access static members of the class
};
#endif