#include <iostream>
#include <cstring>

using namespace std;

class Mystring {
private:
  char *str; // pointer to a char[] that holds a C-style string
public:
  Mystring();                       // No-args contstructor
  Mystring(const char *s);          // Overloaded contstructor
  Mystring( Mystring &source); // Copy constructor
  Mystring(Mystring &&source);      // Move ctor
  ~Mystring();                      // Destructor
  void display() const;
  int get_length() const; // getters
  const char *get_str() const;
};


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
Mystring::Mystring( Mystring &source) : str{nullptr} {
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
  std::cout << "Copy constructor called" <<std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source) : str{source.str} {
  std::cout << "LHS address: " <<&str << " RHS address: " << &source.str << std::endl;
  source.str = nullptr;
  std::cout << "Move ctor called" << std::endl;
}

//copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
  if(this == &rhs)
    return *this;
  delete [] str;
  str = new char[std::strlen(rhs.str) + 1];
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

int main() {
  Mystring a {"Aadarsh"};
  Mystring b {std::move(a)}; //Move constructor if defined, otherwise copy constructor will be called 
  Mystring c;
  c = b;
  return 0;
}
