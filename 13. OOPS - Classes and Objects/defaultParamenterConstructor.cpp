#include <iostream>
using namespace std;
class Game
{
private:
    string name;
    int players;
    double time;

public:
    Game(string name_val = "None", int no_of_players = 0, double total_time = 0);
}; // this technique of setting the defaut parameter with the constructor initialization list helps to prevent writing multiple constructor for different use cases(with different args)
Game::Game(string name_val, int no_of_players, double total_time)
    : name{name_val}, players{no_of_players}, time{total_time}
{
    cout << "3-args constructor" << endl;
};
int main()
{
    // for each cases below 3-args constructor is called
    Game empty;
    Game chess("Chess");
    Game volleyball("Volleyball", 11);
    Game basketball("basketball", 5, 120);

    return 0;
}