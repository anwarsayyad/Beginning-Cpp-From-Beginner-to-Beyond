//even the vectors implements dynamic memory allocation technique internally with the help of heap
#include <cstddef>
#include<iostream>
using namespace std;

int main(){
  int *int_ptr{nullptr};
  cout << int_ptr <<endl;
  int_ptr = new int; //allocates a dynamic memory on the heap
 //NOTE: this allocated unnamed storage can only be accessed using the pointer variable(because ofcourse we cannot call someone without its name), so its important to understand that if we loose track of the pointer varible, we can no longer access this memory and cannot delete it from the heap (which is disaster in memory terms, known as 'memory leak') 
  cout << int_ptr <<'\t' <<&int_ptr << '\t' << *int_ptr<<endl; //*int_ptr is the value of the variable stored, of the variable which int_ptr is referring to (in our case an unamed memory allocation) and it should be the garbage value as it is not yet defined
  *int_ptr = 100;
  cout << *int_ptr <<endl;
  delete int_ptr;//deallocates the heap memory/free the allocated storage

  ////////////////////////////////////////
  int *array_ptr {nullptr};
  size_t size {};
  cout << "size: " << size <<endl;
  cin >> size;
  array_ptr = new int[size];
  cout <<"Array: " << array_ptr << "\t" << *array_ptr << endl;
  delete [] array_ptr; // [] must be empty 
  return 0;
}
