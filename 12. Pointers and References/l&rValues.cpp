#include <iostream>
using namespace std;

int square(int &n){
  return n*n;
}

int main(){
  //l-values: which are addressable and can be on both right/left side of the assignment operator, NOTE: anything that not an l-value are r-value
  //r-values: not addressable values, such as literals
 int x {100}; //x is l-value ; 100 is r-value
  // 200 = x; // 200 is r-value

  int &ref {x}; //allowed, since, ref is referenced to l-value
  // int &ref = 300; //not allowed, since, ref is referenced to r-value
  
  //r-value can also be temporary variables that c++ creates
  // int max = max(20,40); // max(20,30) is an r-value

  square(x); //OK
  // square(4); //Error, since, 4 an r-value (not addressable)
  return 0;
}
