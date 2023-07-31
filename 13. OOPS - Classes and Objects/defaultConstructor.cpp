#include <iostream>
#include <string>
using namespace std;

class Player {
private:
  std::string name;
  int health;
  int xp;

public:
  void setName(std::string name_val) { name = name_val; }
  std::string getName() { return name; }

  Player() { // this will make sure the attributes gets assigned to some values(but NOTE: we are still doing the assignment here, initialilzation is not done here in this example), and
             // garbage values are not stored
    name = "None";
    health = 0;
    xp = 0;
  }
  Player(string name_val, int health_val, int xp_val) {
    name = name_val;
    health = health_val;
    xp = xp_val;
  }
};

int main() {
  Player
      aadarsh; // this will create the "no-args default" constructor, if Player
               // constructor is not defined in the class, NOTE: and garbage
               // value will be stored in the attributes, to avoid getting the
               // garbage value, we can create a Player() constructor with
               // default values of the attributes(still not a good practice, as we are still doing the assignment, true initialilzation is not done in the example,NOTE: We have to use "constructor initialilzation list" technique to do the true initialilzation 
  // NOTE: if any type of constructor(with args or without args) are created in
  // the class, then c++ will not generate the default constructor
  aadarsh.setName("aadarsh");
  cout << aadarsh.getName() << endl;

  Player atul{"atul",100,50};
  cout << atul.getName() << endl;

  Player *priya {nullptr};
  priya = new Player("priya",100,100);

  cout << priya->getName() << endl;
  delete priya;
  return 0;
}
