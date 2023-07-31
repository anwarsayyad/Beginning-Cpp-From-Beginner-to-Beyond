#include <iostream>
#include <string>
using namespace std;

class Human {
public:
  string name;
  string gender;
  unsigned int age;
  string power{"President"}; //this is one way to initialize, instead of "constructor initialization list " technique (but is not preferred)

  Human() : gender{"None"},name{"None"}, age{0} { // after the : is the constructor initialization using list initialization technique, This is the true initialization, meaning: constructor is initialized with these values without ever storing a garbage value in the process(these are the first values to get initialized)
    // One side NOTE: order of initialization will not be the the order of the "constructor initialization list" order, but it will be in the order of attributes that has been declared for the class(in our case: name, gender and then age)
    cout << "Human::Human() constructor is called with no-args" << endl;
  };
  Human(string name_val, string gender_val, unsigned int age_val)
      : name{name_val}, gender{gender_val}, age{age_val} {
    cout << "Human::Human() constructor is called with 3 args" << endl;
  }
};

int main() {
  Human aadarsh;
  Human atul("atul", "Male", 23);
  return 0;
}
