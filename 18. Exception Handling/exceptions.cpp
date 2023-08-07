#include <iostream>
#include <string>
using namespace std;

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
      throw 0; // recommended to throw objects
    if (hr < 0 || km < 0)
      // throw "negative number error"; //this won't work
      throw string{"negative number error"};
    km_per_hr = static_cast<double>(km) /
                hr; // static_cast will cast km to double, and since 1 operand
                    // is double, the operation will be done for doubles and the
                    // output will be double as well
    // NOTE: for doubles division, if denominator = 0, then result is "inf" (aka
    // infinity) ("-inf" if numerator is negative) if denominator and numerator
    // both are 0, then result is "nan" (aka not a number)

    cout << "Speed(km/hr): " << km_per_hr << endl;
  } catch (int &er) {
    cerr << er << endl;  // std::cerr is special type to display errors
  } catch (string &er) { // we can catch multiple expections like this
    cerr << er << endl;
  } catch (...) { // catch all statement(will catch any type of error)
    cerr << "Unknown error"
         << endl; // here we dont have access to the erro object
  }
  return 0;
}
