#include <iostream>
#include <string>

class Player {
private:
  std::string name;
  int health;
  int xp;

public:
  void set_name(std::string name_val) { name = name_val; }

  // overloaded constructors (constructors and Desctructors dont have return values)
  Player() { std::cout << "NO args constructor called" << std::endl; }

  Player(std::string name) {
    std::cout << "string args constructor called" << std::endl;
  }

  Player(std::string name, int health, int xp) {
    std::cout << "3 the args constructor called" << std::endl;
  }
  // Desctructor(Can never have overlaoded destructor(infact there is nothing like overloaded destructor, it doesn't make any sense ), or more than 1 destructor as destructors are automatically called by c++ and if there would be more destructor, c++ will not be able to figure out which one to call )
  ~Player() { std::cout << "Desctructor called for: " << name << std::endl; }
};

int main() {
  {
    Player aadarsh;
    aadarsh.set_name("aadarsh");
  } // after the scope(in our case after this block), the Desctructor is
    // automatically called, as the object is destroyed after this block
  // lets suppose there were { } to go out of the scope, and the variable was in the scope till the whole program, then, the Desctructor will be called for that variable after the main() ends (i.e, after the program ends)
  {
    Player aadarsh;
    Player atul("a", 100, 40);
    Player priya("p");

    aadarsh.set_name("aadarsh");
    atul.set_name("atul");
    priya.set_name("priya");
  } // automatic call of Desctructor, but in stack order (LIFO), so Desctructor
    // for object priya will be called first, for atul second, and for aadarsh
    // at the last.
  {
    Player *enemy = new Player;
    enemy->set_name("Enemy");

    Player *BossEnemy = new Player("Boss", 1000, 30);
    BossEnemy->set_name("BOSS");

    delete enemy; // after the memory is deallocated, there is automatic call of
                  // Desctructor here too.
    delete BossEnemy; // but it happens explicitly when we delete the memory, if
                      // we dont delete and even though we are out of scope, the
                      // Desctructor will never be called
  }
  return 0;
}
