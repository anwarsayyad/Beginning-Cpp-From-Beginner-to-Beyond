#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<char> vec1 {'a','e','i','o','u'};
  vector<int> days (365,1);

  cout<< days[300] <<endl;
  // cout << days.at(400) <<endl;// .at method has bounce checking and halts the compiler when found out of bounds
  cout << days[400] <<endl; //whereas, simply fetching the out of bound indexed value like this will result in garbage value being output
  return 0;

}
