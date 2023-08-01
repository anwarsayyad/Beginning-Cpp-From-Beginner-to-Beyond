#include <iostream>
using namespace std;

class Shallow
{
public:
    int *data;

public:
    void setData(int d) { *data = d; };
    int getData() { return *data; }

    // constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

Shallow::Shallow(int d) : data{new int} // Bad Practice, to allocate dynamic mem here,(as it is an example of shallow copy), which is very bad when we are using raw pointers
{
    *data = d;
    cout << "checking heap allocated address from the constructor: " << data << endl;
}

// shallow copy (infact it the default way c++ implement copy constructors when we dont create a copy constructor manually)
Shallow::Shallow(const Shallow &source) : data{source.data}
{
    cout << "Copy constructor - shallow copy with pointer address" << source.data << endl;
    // after going out of scope the destructor will be called, "data" will be freed of the same address that it points to the original objects's heap memory (created with "new"), although we are storing the copy with copy constructor, but the heap memory is pointing to the same address;
}

Shallow::~Shallow()
{
    delete data; // the problem occurs when we free heap memory for the same adderss twice (for that reason, we need to use the deep copy method, so that the objects that are copy of the original objects will have their seperate heap memory and it will not conflict while freeing up the memory)
    cout << "Destructor freeing data" << endl;
}
int main()
{
    Shallow aadarsh(23);
    Shallow atul{aadarsh}; // shallow copying(because of the way copy constructor is implemented)
    return 0;
}