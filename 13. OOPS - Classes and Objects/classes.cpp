#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
  // attributes
public:
  string name{"Player"}; //initializing the values, creates default value for each objects
  int health{100};
  int xp{3};

  // methods
  void talk(string);
  bool isDead();
};

class Account {
public:
  // attributes
  string name{"Account"};
  double balance{0.0};

  // methods
  bool deposit(double);
  bool withdraw(double);
};

int main() {

  Account Daya;
  Account BabuBhaiya;

  Player Aadarsh;
  Player Atul;
  Aadarsh.name = "aadarsh";
  Aadarsh.health = 100;
  Aadarsh.xp = 50;
  cout << "Name: " << Aadarsh.name << " health: " << Aadarsh.health <<" xp: " << Aadarsh.xp<< endl;
  
  Player player[]{Aadarsh, Atul};
  vector<Player> player_vec{Aadarsh};
  player_vec.push_back(Atul);

  Player *enemy{nullptr};
  enemy = new Player;

  (*enemy).name = "PiroPilayer";
  cout << (*enemy).name << endl;

  enemy -> name = "PiroPlayer";//arrow operator(Internally it does the same this as above, first dereference, and then use the . operator) It is more convenient and used more often
  cout << enemy->name <<endl;

  delete enemy;
  return 0;
}
