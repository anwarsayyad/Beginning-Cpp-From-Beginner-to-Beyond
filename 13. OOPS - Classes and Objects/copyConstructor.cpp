#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() { return xp; }
    Player(string name_val = "None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    Player(const Player &source); // using const- because we dont want to change the original object, and using &ref becasue we want to have the reference, not the copy

    // Destructor
    ~Player() { cout << "Destructor called for: " << name << endl; }
};

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    cout << "Three-args constructor for " + name << endl;
}
// copy constructor implementation
Player::Player(const Player &source)
    //: name{source.name}, health(source.health), xp{source.xp}

    //    or use delegating constructor:
    : Player{source.name, source.health, source.xp}
{
    cout << "Copy constructor - made copy of: " << source.name << endl;
}

// pass by-value (copy)
void display_player(Player p)
{
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}

int main()
{
    Player empty{"XXXXXX", 100, 50};
    Player my_new_object{empty};

    display_player(empty);

    // Player frank{"Frank"};
    // Player hero{"Hero", 100};
    // Player villain{"Villain", 100, 55};

    return 0;
}
// BEST PRACTICES
// provide a copy constructor when your class has raw pointer members (because by default only the pointer(shallow copy) is copied and not the value it is pointing to(not deep copy))

// provide the copy constructor with a const reference paramenter

// Use STL classes as they already provide copy constructors

// Avoid using raw pointer data members to avoid complexity,and use smart pointers intead
