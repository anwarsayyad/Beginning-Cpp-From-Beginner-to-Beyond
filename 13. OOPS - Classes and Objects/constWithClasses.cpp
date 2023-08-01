#include <iostream>
#include <string>
using namespace std;

class Dummy
{
private:
    string name;
    int number;

public:
    string getName() const { return name; }; // the const qualifier  makes sure that the content of the function can not be changed ever, and if objects of this method class defined with const varibles can now have access to this method(since C++ expects to only access methods that have const qualifier attached to it, if its corresponding object is defined with const, example see below)
    int getNumber() { return number; }

    Dummy(string name_val) : name{name_val} { cout << "Constructor called" << endl; }
};

void displayPlayer(const Dummy &source)
{
    // cout << source.getNumber() << endl; // error since the copy object "source" defined with const, is expecting getNumber() method to have a const qualifier
}
int main()
{
    const Dummy aadarsh{"aadarsh"};
    // since it is created with const keyword,it simply means, now aadarsh objects' attributes cannot be changed,also all the methods will be in-accessible by default (as C++ assumes methods might change the attribute values, it doesn't figure it out on its own)
    cout << aadarsh.getName() << endl; // this is accessible because getName() method has const qualifier set

    displayPlayer(aadarsh);
    return 0;
}