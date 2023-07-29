#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vector1;
  vector<int> vector2;
  vector<vector<int>> vector2d;
  vector1.push_back(100);
  vector1.push_back(400);
  vector2.push_back(200);
  vector2.push_back(800);

  cout << vector1.at(0)<< " " << vector1[1]<<" of size: "<< vector1.size() << endl;
  vector2d.push_back(vector1);
  vector2d.push_back(vector2);

  cout << vector2d[0][1] << endl;

  vector1.at(1) = 10;
  cout << vector2d[0][1]<<"\t"<< vector1.at(1) << endl; //vector2d has not changed, because a copy has been stored instead of the reference NOTE: thats how the vectors work
  return 0;
}
