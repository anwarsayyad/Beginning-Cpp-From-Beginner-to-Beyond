#include <iostream>
using namespace std;

class DivideByZeroException {};//can have all the details of the error
class NegativeValueException {};

double calculate(int km, int hr){
  return static_cast<double>(km)/hr;
}
int main() {
  int km{};
  int hr{};
  double km_per_hr{};

  cout << "Enter the km: ";
  cin >> km;
  cout << "Enter the hr: ";
  cin >> hr;

  try {
    if (hr == 0)
      throw DivideByZeroException();//user defined class 
    if (hr < 0 || km < 0)
      throw NegativeValueException();//user defined class 
    km_per_hr = calculate(km,  hr);

    cout << "Speed(km/hr): " << km_per_hr << endl;
  } catch (const DivideByZeroException &er) {
    cerr << "You cannot divide by zero" << endl;  
  } catch (const NegativeValueException &er) {
    cerr << "Km and hr cannot be negative" << endl;
  } 
  return 0;
}
