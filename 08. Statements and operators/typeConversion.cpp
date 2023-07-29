#include <iostream>
using namespace std;

int main(){
  int totalMarks {545};
  int subject {4};

  double average {0};

  average = totalMarks/subject; //result: not a double(floating) type 
  cout << average <<endl;

  average = static_cast<double>(totalMarks)/subject; // 'subject' will automatically gets type coerced to double (as out of int and double, double is the bigger sized datatype)
  // result: a double type
  cout << average << endl;
  return 0;
}
