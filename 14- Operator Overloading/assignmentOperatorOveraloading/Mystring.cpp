#include "Mystring.h"
#include <cstring>
#include <iostream>

// No-args constructor
Mystring::Mystring() : str{nullptr} {
  str = new char[1];
  *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr} {
  if (s == nullptr) {
    str = new char[1];
    *str = '\0';
  } else {
    str = new char[std::strlen(s) + 1];
    std::strcpy(str, s);
  }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr} {
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
  std::cout << "Copy constructor called" <<std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source) noexcept : str{source.str} {
  std::cout << "LHS address: " <<&str << " RHS address: " << &source.str << " Assigned: " << *source.str << std::endl;

  source.str = nullptr;
  std::cout << "Move ctor called" << std::endl;
}

// copy operator assignment(Overloaded assignment)
Mystring &Mystring::operator=(
    const Mystring
        &rhs) { // We must return from this assignment, as want to allow
                // multiple assignment as well, which is like this- a=b=c=d;
  std::cout << "COPY assignment" << std::endl;
  if (this == &rhs) // NOTE: this is LHS side, &rhs is RHS
    return *this;
  delete[] this->str;
  str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(
      str, rhs.str); // copy RHS string to new heap allocated string str in LHS
  return *this;
}

// move operator assignment(Overloaded assignment)
Mystring &Mystring::operator=(Mystring &&rhs) noexcept{
  std::cout << "MOVE assignment" << std::endl;
  if( this == &rhs){
    return *this;
  }
  delete [] str;
  str=rhs.str;
  rhs.str = nullptr;
  return *this;
}

// Destructor
Mystring::~Mystring() { delete[] str; }

// Display method
void Mystring::display() const {
  std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char *Mystring::get_str() const { return str; }
