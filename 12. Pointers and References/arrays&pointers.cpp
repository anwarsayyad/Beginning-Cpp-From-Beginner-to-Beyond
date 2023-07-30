#include <iostream>
using namespace std;

int main(){
  int scores[] { 100, 200, 300};
  cout << scores << "\t" << *scores << endl; //scores will point to the first element in the address

  int *scores_ptr {scores};
  cout << scores_ptr << "\t" << *scores_ptr << endl;//scores_ptr will do the same task, and the output will be exactly same(pointing to same address location) NOTE: in C++ arrays are just pointer references

  cout << scores_ptr << "\t" << (scores_ptr + 1)<< "\t" << (scores_ptr + 2)<< endl; //addition of any integer with the pointer variable means it increments the pointer address (eg. for int types it increments by 4/8 bytes depending on the size of the dataype)
  cout << *scores_ptr << "\t" << *(scores_ptr + 1)<< "\t" << *(scores_ptr + 2)<< endl;//dereferencing the values (it must output the array values )

  /* Subscript and offset notatioin equivalence
    * int array_name[] {1,2,3,4,5};
    * int *pointer_name {array_name};
    *
      *   SUBSCRIPT NOTATION        OFFSET NOTATION
      *   array_name[index]         *(array_name+index)
      *   pointer_name[index]       *(pointer_name+index)
  */

  cout << scores_ptr[2] <<"\t"<< *(scores_ptr + 2)<< endl;
  return 0;
}
