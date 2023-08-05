#include <iostream>
#include <vector>

using namespace std;
void func_lValue(int &num) { cout << num << ": from func_lValue()" << endl; };

void func_rValue(int &&num) { cout << num << ": from func_rValue()" << endl; };

//we can also use function overloading and define two funcions, one accepts l-value and other r-value
class Move {
private:
    int *data;
public:
    void setData(int d) { *data = d; };

    int getData() { return *data; };

    Move(int d);
    //copy constructor
    Move(const Move &source);
    //Move Constructor(that what we are here for)
    Move(Move &&source);
    ~Move();
};

Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "constructor called for: " << *data << " Address: " << data << endl;
};

Move::Move(const Move &source){
    data = new int;
    *data = *source.data;
    cout << "Copy constructor -deep copy for:" << *data << " Adderss: " << data << endl;
}

Move::Move(Move &&source):data{source.data}{
   source.data = nullptr;
   cout << "Move constructor called for: " << *data << " Address: " << source.data << endl;
}
Move::~Move() {
    if(data != nullptr) {
        cout << "Destructor called for not-nullptr" << endl;
    }
    else{
        cout << "Destructor called for nullptr" << endl;
    }
    delete data;
}

int main() {
    int x{100};
    int &l_ref{x}; // l value reference, only stores l-values
    l_ref = 200;

    int &&r_ref{500}; // r-value reference, only gets initialized to r-values
    r_ref = 400;
    r_ref = x; //but can be assigned an l-values
    cout << r_ref << endl;
//     int &&r_value_ref = x; // error (r-value reference cannot store an l-value)

    func_lValue(x);
//    func_lValue(30); //cannot bind an r-value of l-value reference
    func_rValue(30);
//    func_rValue(x); //cannot bind an l-value to r-value reference

    Move aadarsh{40};
    Move atul{aadarsh};

    vector<Move> vec;
    vec.push_back(Move{30}); //parameter Move{30} is not addressable(i.e, it is an r-value) and hence the copy constructor will be called(until and unless we specify the move-constructor)
    vec.push_back(Move{31});
    return 0;
}

/*
 * Why MOVE CONSTRUCTOR-
 * -It is more efficient as we are not always copying the objects(as with copy
 * constructor), deep copy in copy constructor takes even more memory and in
 * such case MOVE constructor suits best, as it just moves the object rather
 * than copying it.
 */

/*
 * r-value reference-
 * Used in moving semantics and perfect forwarding
 * Move semantics is all about r-value reference
 * Used by move constructor and move assignment operator to efficiently move and
 * object rather than copy it
 * R-value reference operator (&&)
 *
*/
