#include <iostream>
#include <string>
using namespace std;

int main() {
  string name1{"Aadarsh"};
  string name2{"Aadarsh"};
  int score[]{1, 2, 3, 4, -1};

  string *p1{&name1};
  string *p2{&name2};
  string *p3{&name1};
  int *score_ptr{score};
  // comparison
  cout << (p1 == p2) << "\t" << (p1 == p3) << endl;
  cout << (*p1 == *p2) << "\t" << (*p1 == *p3) << endl;

  // increment
  while (*score_ptr != -1) {
    cout << *score_ptr << " ";
    score_ptr++;
  }
  cout << "\n";
  score_ptr = score;
  while (*score_ptr != -1) {
    cout << *score_ptr++ << " ";
  }
  cout << "\n";

  // substarct
  char tribe[]{"African"};

  char *char_p1 = {&tribe[0]};
  char *char_p2 = {&tribe[3]};

  cout << *char_p2 << " is " << (char_p2 - char_p1) << " characters away from " << *char_p1 << endl;

  return 0;
}
