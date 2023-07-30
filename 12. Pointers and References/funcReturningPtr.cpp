#include <iostream>
using namespace std;

int *largestNumber(int *x, int *y) {
  if (*x > *y)
    return x; // return the address
  else
    return y; // return the address
}
// returning a dynamic allocated memory
int *create_array(size_t size, int initialVal = 0) {
  int *newStorage{nullptr};
  newStorage = new int[size];
  for (size_t i{0}; i < size; ++i) {
    *(newStorage + i) = initialVal;
    //newStorage[i] = initialVal; //OR
  }
  return newStorage;
}

// Never return a pointer to a local variable
// NOTE/REASON: the local variable in a function can not be tracked if after the function is done executing (because the varibles are created in a stack and after the functions are returned they just never exist)
//
// int *dont_do_this(){
//   int size {};
//   //...
//   return &size;//see the even the compiler warns you
// }
//
// int *or_this(){
//   int size {};
//   int *ptr {&size};
//   //...
//   return ptr;
// }

int main() {
  int a{100};
  int b{200};
  int *large_ptr{nullptr};
  large_ptr = largestNumber(
      &a, &b); // accessing the address and storing it in a pointer of same type
  cout << "Larger no. is: " << *large_ptr << endl;

  int *arr{create_array(100, 13)};
  // use this heap allocated memory with the help of this pointer anywhere until
  // you delete it manually
  cout << arr<< "\t" << arr[3] <<endl;
  delete [] arr; // make sure to delete after use to not create a memory
                     // leak (as the memory is dynamically created in heap)
  return 0;
}
