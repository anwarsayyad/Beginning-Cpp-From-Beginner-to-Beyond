#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a{100};
  int &ref{a};

  cout << a << "\t" << ref << endl;

  a = 200;

  cout << a << "\t" << ref << endl;

  ref = 300;

  cout << a << "\t" << ref << endl;
  //////////////////////////////////////////////////////
  vector<string> names{"atul", "aadarsh"};
  for (auto &str : names) { //&str is storing the reference, hence the orginial
                            // vector is changed
    str = "NoName";
  }
  for (auto const &str: names){ //const will prevent the data change
    cout << str << endl;
   }// NOTE: reference based techniques are more efficient as it doenot allow
  // copies to the variables to be made, wherever possible use reference based
  // calls, to safeguard the data change/loss use the const keyword
  for (auto str : names) { // copy has beed stored, no change in actual vector
    str = "null";
  }
  for (auto const &str: names){
    cout << str << endl;
  }
}
