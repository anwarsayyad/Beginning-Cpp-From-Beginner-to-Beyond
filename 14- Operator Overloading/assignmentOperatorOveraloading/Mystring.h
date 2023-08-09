#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
  char *str; // pointer to a char[] that holds a C-style string
public:
  Mystring();                       // No-args contstructor
  Mystring(const char *s);          // Overloaded contstructor
  Mystring(const Mystring &source); // Copy constructor
  Mystring(Mystring &&source) noexcept;      // Move ctor
  ~Mystring();                      // Destructor
  void display() const;
  int get_length() const; // getters
  const char *get_str() const;
  Mystring &operator=(const Mystring &rhs); //Copy assignment
  Mystring &operator=(Mystring &&rhs) noexcept; //Move assignment

};

#endif // _MYSTRING_H_
