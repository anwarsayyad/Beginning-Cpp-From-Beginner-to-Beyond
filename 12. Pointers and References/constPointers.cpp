#include<iostream>
using namespace std;

int main(){
  //pointer to constants
  int a {20};
  int b {99};

  const int *p1 {&a};

  // *p1 = 50; //error
  p1 = &b; // OK
  
  //constant pointers
  int *const p2 {&a};
  *p2= 40; //OK
  // p2 = &b; //error

  //constant pointers to constants 
  const int *const p3 {&a};
  // *p3 = 30; //error
  // p3 = &b;  //error
  return 0;
}
