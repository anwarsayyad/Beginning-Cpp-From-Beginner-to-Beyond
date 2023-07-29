// #include <cctype>
#include <cstddef>
#include <iostream>
// #include <cstring>
#include <string>
using namespace std;

int main() {
  string s1;
  string s2 {"Aadarsh"};
  string s3 {s2};
  string s4 {"Aadarsh", 3};
  string s5 {s3, 0,2};
  string s6 (10, 'Z');

  cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " " << s6 <<endl;
  
  string p1 {"C++"};
  string p2 {"is a powerful"};

  string sentence1 = p1 + " " + p2 + " language"; //concatenation of c++ and c string is valid statement NOTE: here " language" and " " are C style string literals
  // string sentence2 = "C++" +" is cool" + p2; //Illegal(concatenation of c style string this way is invalid)
  
  // cout << s2.at(50); //.at method for strings too ensures the out of bound checks
  
  for (char c: s2) cout << c << endl; //prints each characters
  for (int c: s2) cout << c << endl; // prints ASCII value of each characters

  cout << (s1 == "aa") << endl; //comparison of c-style and c++ style strings are valid, NOTE: here "aa" is a c-style literal and s1 is a C++ string
  cout << ("ab" == "ab") << endl; //comparison of two c-style string literals are not allowed

  //substr
  cout << s2.substr(0,3) << endl;

  //find()
  cout << s2.find("dar")<<endl;//returns the starting position of the found character 
  cout << s2.find("a",2) << endl;// start the search from index 2 instead of default 0
  // cout << s2.find("z")<<endl;
  
  //important methods-
  //erase() and clear()
  //length()
  //cin.getline() would read until the '\n'(enter) is pressed by user rather than a whitespace as the delimiter
  // cin >> s1; //stores upto a whitespace
  // cout << s1 << endl;

  getline(cin, s1);//instead use getline() to store a paragraph
  // getline(cin, s1, '*'); //set your own delimiter 
  cout << s1 << endl;


  /////////////////////////Lets Find a word/////////////////////
  string word {};

  cout << "Enter the word to find: ";
  cin >> word;

  size_t position = s1.find(word); //size_t is a special datatype that is always positive(unsigned)and has some other propeties also(which i am unfamiliar of it now, i will learn as i go), it is usually the correct type to handle specific variables (in our case 'position')
  if (position != string::npos) cout << "Found" << word << " at position: " << position << endl; //string::npos (no position), if the string is not found then, the default return value is string::npos(no position)
  else cout << "Sorry, " << word << " Not Found" <<endl;
  
  
  // cout << sizeof(size_t) << endl;
  return 0;
}
