#include <iostream>
using namespace std;

int main() {
  int scores[]{39, 53, 242, 24};
  for (int score : scores)
    cout << score << endl;
  for (auto score : scores) // auto tells compiler to automatically figure out the datatype  defined for the iterable(array,vector etc)
    cout << score << endl;

  for(auto temp: {45.3,53.4,23.0}) cout << temp <<endl; //using list initialization within the loop

  for (auto c: "Aadarsh") cout << c << endl;
  return 0;
}
