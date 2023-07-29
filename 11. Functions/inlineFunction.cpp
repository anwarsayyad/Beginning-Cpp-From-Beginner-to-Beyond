//sometimes the function we create is so simple and short that the job of doing the the "function activation, putting the function on stack, tracking all the return values and address etc" becomes much more complex than the actual code logic inside the function (i.e, compiler will take more time doing all those internal process than the actual function logic takes)
//In those cases, we can use "inline" functions which would skip all those internal process told above, and directly do the execution
//NOTE: creating a lot of inline function will result in large binary generation, which is ofcourse avoided

#include<iostream>
using namespace std;

inline int add_numbers(int x, int y){ //NOTE: advanced compilers nowadays dont need us to make inline functions, it will automatically figure out which functions should be used as inline or normal functions, and change its implementation internally
  return x+y;
}

int main(){
  int result {0};
  result = add_numbers(100,200);
  cout << result <<endl;
  return 0;
}
