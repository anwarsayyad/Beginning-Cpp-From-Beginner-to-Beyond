//A simple explanation of how ctor and dtor are called behind the scene
#include <iostream>
using namespace std;
class Base {
private:
	int value;
public:
	Base() {
		cout << "Base ctor called" << endl;
	}
	Base(int x) :value{ x } { cout << "Base(int) overloaded ctor called" << endl; }
	~Base() {
		cout << "Base destructed " << endl;
	}
};

class Derived : public Base { //public inheritance 
	//using Base::Base; //will allow us to "inherit" the non-special ctor from the Base class, but completely ignore its own class [we would need to handle manullay] (special ctor are like- default ctor, copy ctor etc), anything other than those are non-special

private:
	int doubled_value;
public:
	/*Derived() {
			cout << "Derived ctor called" << endl;
		}
		Derived(int x) :doubled_value{ x * 2 } { cout << "Derived(int) overloaded ctor called" << endl; }
		*/

		//below implementation is, explicitally calling the Base ctor (whateve ctor we want)
	Derived() : Base{} {
		cout << "Derived ctor called" << endl;
	}
	Derived(int x) :Base{ x }, doubled_value{ x * 2 } {
		cout << "Derived(int) overloaded ctor called" << endl;
	}



	~Derived() {
		cout << "Derived destruced" << endl;
	}
};

//Conclusion: the derived ctor(either no-args or overloaded ctor) will automatically call the base class ctor(no-args) only, to make it inherite the overload ctor(non-special), we need to use the "using Base::Base", but when we do the actual implementation of overloaded ctor in the derived class, the "using Base::Base" will be ignored/overwritten and again the same no-args ctor will be called (to make it explicitly call the ctor that we want it to call, we should use some syntax like this- Derived::Derived(int x) :Base{x}, doubled_value{x*2} { //code}; )
//Destructors will be called in stack manner, first derived class dtor, then the base class dtor is called

int main()
{
	//Base base0;
	//Base base1{ 30 };
	Derived derived0;
	Derived derived1{ 34 };
}

//A Derived(child) class does not Inherit-
//	- Base class constructor(incl. copy/move ctor),  however it can be invoked
//	- Base class destructor, however it can be invoked
//	- Base class overloaded assignment operators, however it can be invoked
//	- Base class friend functions,(CANNOT be invoked, as friend relation cannot be inherited in c++)
