// Section 14
// Mystring - starting point
#include "Mystring.h"
#include <iostream>

using namespace std;

int main() {
  // Mystring empty;          // no-args constructor
  // Mystring larry("Larry"); // overloaded constructor
  // Mystring stooge{larry};  // copy constructor

  // empty.display();
  // larry.display();
  // stooge.display();

  Mystring a =
      "Aadarsh"; // NOTE: this is initialization(not assignment), hence
                 // constructor will be called, not the copy/move assignment
  // NOTE: internally, operator= mehod is called, so actual syntax is
  // something like this: a.operator=(b);

  a = "Atul"; // "Atul" is r-value(sice strings will be stored in a temp varible inside) , hence copy/move assignment will be called
  //- first, the constructor will be called initializing a temporary varible
  // with the value of "Atul",
  //- then, the overloaded assignment operator will be called

  // Mystring b{std::move(a)}; // force move (here, `a` is an l-value, so by
                            // default copy constructor will be called, to make
                            // it use move constructor instead, use std::move)
  // NOTE: but dont use, it can cause unexpected behaviour (if you dont know about it), eg, the below line `b = a` will cause segmentation fault(idk why) after i do Mystrin b{std::move(a)}
  // b = a;
  
  Mystring c;
  c=a; // here a is an l-value hence COpy assignment is done

  c = Mystring{"Hola"}; //move assignment, because, Mystrin{"HOla"} will create a temp varible to store its value
  return 0;
}
