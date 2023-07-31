#include<iostream>
#include<vector>
using namespace std;

int main(){
  int *value {nullptr};//uninitialized pointers can cause problem, best practice is to always initialize it with 'nullptr' which represents address zero(implies pointer is pointing nowhere)
  cout << value << endl;

   return 0;
}
