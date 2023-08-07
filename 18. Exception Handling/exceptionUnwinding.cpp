#include <iostream>
using namespace std;

// declaration
void func_a();
void func_b();
void func_c();

void func_a() {
  cout << "Pushing on stack: function a" << endl;
  func_b();
  cout << "stacking off: function a" << endl;
}

void func_b() {
  cout << "Pushing on stack: function b" << endl;
  try {
    func_c();
  } catch (int &er) {
    cout << "Catching exception on func_b: " << er << endl;
  }
  cout << "Stacking off: function b" << endl;//notice how this line gets executed(because we have handled the exception beforehand safely)
}
void func_c() {
  cout << "Pushing on stack: function c" << endl;
  throw 100; // 1- now the func_c() will get off the stack and next statement
             // will not be printed
  // 2- it will rewinding until the main function and check for the caller
  // function for execption handling (catch statement), if no catch function is
  // found, that function will immediately get off the stack as well(without
  // executing anything in the function), and if catch function is found and
  // handled, then remaining execution of the function will get executed(if any)
  // and the function will get off the stack safely
  // 3: NOTE: the worst possible situation that can arise while unwinding is that, we have raw pointers allocating some memory in heap, and it never gets deallocated while unwinding (recommended to use RAII smart pointers though), if we dont catch exception there
  cout << "Stacking off: function c" << endl;
}

int main(int argc, char *argv[]) {
  try {
    func_a();
  } catch (int &er) {
    cout << "Catching exception on main: " << er << endl;
  }
  return 0;
}
