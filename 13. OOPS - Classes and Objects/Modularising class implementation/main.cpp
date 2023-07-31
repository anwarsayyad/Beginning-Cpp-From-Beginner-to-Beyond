#include "Account.h" //make sure not to include .cpp file
#include <iostream>

int main() {
  Account babuBhaiya;
  Account raju;

  babuBhaiya.set_balance(423324.22);
  raju.set_balance(28.23);

  std::cout << babuBhaiya.get_balance() << std::endl;
  std::cout << raju.get_balance() << std::endl;
  return 0;
}
