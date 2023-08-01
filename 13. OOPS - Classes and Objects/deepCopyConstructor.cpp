#include <iostream>
using namespace std;

class Deep
{
public:
    int *data;

public:
    void setData(int d) { *data = d; };
    int getData() { return *data; }

    // constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    // Destructor
    ~Deep();
};

Deep::Deep(int d) : data{new int}
{
    *data = d;
    cout << "checking heap allocated address from the constructor: " << data << endl;
}

// // Deep copy
// Deep::Deep(const Deep &source) : data{new int}
// {
//     *data = *source.data;
//     cout << "Copy constructor - Deep copy with pointer address" << data << endl; // check the addresses are different, as we allocated a different heap memory
// }

// Deep copy with delegating constructor initialization
Deep::Deep(const Deep &source)
    : Deep{*source.data} // TODO: check what is happening internally in this case of delegation
{
    // *data = *source.data;
    cout << "Copy constructor - Deep copy with pointer address" << data << endl; // check the addresses are different, as we allocated a different heap memory
}
Deep::~Deep()
{
    delete data;
    cout << "Destructor freeing data"
         << "\n"
         << " Garbage value of pointed-to value after the memory is deallcoted: " << *data << " But Memory address still accessible: " << data << endl;
}

void display_deep(Deep s)
{ // not a method(class member function),
    // Remeber: whenever the pass by value is done with an obj the copy constructor is called(either the default or the manually created on), so even in this case the copy constructor will be called(to be specific, our own deep copy constructor will be called)
    cout << s.getData() << endl;
}

int main()
{
    Deep aadarsh(23);
    Deep atul{aadarsh}; // Deep copying(because of the way copy constructor is implemented)
    display_deep(atul); // Deep copying
    return 0;
}