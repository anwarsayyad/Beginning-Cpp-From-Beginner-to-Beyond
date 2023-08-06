#include <iostream>
using namespace std;

struct Student{ 
  string name;//by default the member modifiers are public in struct (this is the only difference between struct and classes, because class members by default are private in nature)
  int age;

};

int main(){
  Student aadarsh;
  aadarsh.name = "atul";
  aadarsh.age = 23;

  cout << "Name: " << aadarsh.name<<" Age: " << aadarsh.age<< endl;
  return 0;
}
