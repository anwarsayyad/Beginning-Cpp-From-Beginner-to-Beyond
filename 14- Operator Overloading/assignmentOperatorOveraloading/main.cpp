// Section 14
// Mystring - starting point
#include "Mystring.h"
#include <iostream>

using namespace std;

int main() {
  Mystring empty;          // no-args constructor
  Mystring larry("Larry"); // overloaded constructor
  Mystring stooge{larry};  // copy constructor

  // empty.display();
  // larry.display();
  // stooge.display();

  Mystring a =
      "Aadarsh"; // NOTE: this is initialization(not assignment), hence
                 // constructor will be called, not the copy/move assignment

  cout << a.get_str() << endl;
  a = "Atul"; // this is assignment, hence copy/move assignment will be called
  //- first, the constructor will be called initializing a temporary varible
  // with the value of "Atul",
  //- then, the overloaded assignment operator will be called
  cout << a.get_str() << endl;
  a = larry; // NOTE: internally, operator= mehod is called, so actual syntax is
             // something like this: a.operator=(b);

  cout << a.get_str() << endl;

  Mystring b {a}; //Move constructor if defined, otherwise copy constructor will be called 
  return 0;
}
