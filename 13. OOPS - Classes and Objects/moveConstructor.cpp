#include <iostream>
#include <vector>

using namespace std;
void func_lValue(int &num) { cout << num << ": from func_lValue()" << endl; };

void func_rValue(int &&num) { cout << num << ": from func_rValue()" << endl; };

// we can also use function overloading and define two funcions, one accepts
// l-value and other r-value
class Move {
private:
  int *data;

public:
  void setData(int d) { *data = d; };

  int getData() { return *data; };

  Move(int d);
  // copy constructor
  Move(const Move &source);
  // Move Constructor(that what we are here for)
  Move(Move &&source) noexcept;
  ~Move();
};

Move::Move(int d) {
  data = new int;
  *data = d;
  cout << "constructor called for: " << *data << " Address: " << data << endl;
};

Move::Move(const Move &source) {
  data = new int;
  *data = *source.data;
  cout << "Copy constructor -deep copy for:" << *data << " Adderss: " << data
       << endl;
}

Move::Move(Move &&source) noexcept: data{source.data} {
  source.data = nullptr;
  cout << "Move constructor called for: " << *data
       << " Address: " << source.data << endl;
}
Move::~Move() {
  if (data != nullptr) {
    cout << "Destructor called for not-nullptr" << endl;
  } else {
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
  r_ref = x; // but can be assigned an l-values
  cout << r_ref << endl;
  //     int &&r_value_ref = x; // error (r-value reference cannot store an
  //     l-value)

  func_lValue(x);
  //    func_lValue(30); //cannot bind an r-value of l-value reference
  func_rValue(30);
  //    func_rValue(x); //cannot bind an l-value to r-value reference

  Move aadarsh{40};
  Move atul{aadarsh};

  vector<Move> vec;
  vec.push_back(
      Move{30}); // parameter Move{30} is not addressable(i.e, it is an r-value)
                 // and hence the copy constructor will be called(until and
                 // unless we specify the move-constructor)
  vec.push_back(Move{31});
  // Important details: So, suppose we do not specify the noexcept for the main
  // constructor, then, everything will be done using the move constructor in
  // our case, but the internal reallocation of the vectors will be using the
  // copy constructor what is internal reallocation of vectors? - remember the
  // statement, vectors does use some default copy constructor internally to
  // make itself dynamic sized (and behind the scences the internal reallocation
  // takes place)NOTE:"A vector internally holds a certain amount of memory, and
  // when you put your data into the vector, it fills that memory up. When the
  // memory is full and you try to add something else, the vector will allocate
  // an entirely new block of memory which is larger than its current one,
  // move/copy all the existing elements across to the new buffer, then
  // deallocate the old buffer (and add the new element). That's how vectors
  // work" also "vector capacity is usually done in powers of two(meaning, each
  // time the new item is found to be pushed on the vector, then the reallocation is done)" NOTE: we have
  // a "reserve()" that is used in vectors to help overcome the drawback of
  // multiple reallocation(which is its slow speed, as every push of item on
  // vector it will lead to reallocation), "if you know how much memory you will
  // be using ahead of time, you should reserve() it, as internal reallocation
  // of vectors is slow", "reserve() doesn't change size though. It changes
  // capacity", with being dynamic is nature, we can cope up with the speed of
  // static-sized array, because we have reduced the internal reallocation down to one (isn't is amazing :D )

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
