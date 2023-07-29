#include <iostream>
using namespace std;

void static_example(){
  static int num = 10; //When this function is called more than once,since, the varible is static, it preserves its previous value, so in our case "num" value will keep on incrementing to 1 everytime this function is called
  num+=1;
  cout << num <<endl;
}
int main(){
  static_example();
  static_example();
}
