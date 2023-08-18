#include "SavingAccount.h"

#include <iostream>

SavingAccount::SavingAccount(double amount, double interestRate) :Account(amount), interestRate{ interestRate } {
	std::cout << "SavingAccount non-special ctor" << std::endl;
}

SavingAccount::SavingAccount() :SavingAccount{ 0.0,3.0 } {
	std::cout << "SavingAccount no-args ctor" << std::endl;
}

void SavingAccount::deposit(double amount) {
	amount += amount * interestRate / 100;
	Account::deposit(amount);  //to be clear, this is not an example of "dynamic binding" either, according to chatgpt following is an example of dynamic binding:

		//Chatgpt zindabad :D

  /*  Static binding and dynamic binding are concepts related to polymorphism in object - oriented programming, particularly in languages like C++.Let's look at examples for both static and dynamic binding in C++.

        1. Static Binding :
    Static binding(also known as early binding) occurs when the method to be called is determined at compile time based on the declared type of the object.This is typical when calling non - virtual functions.

       #include <iostream>

        class Base {
        public:
            void print() {
                std::cout << "Base::print()" << std::endl;
            }
    };

    class Derived : public Base {
    public:
        void print() {
            std::cout << "Derived::print()" << std::endl;
        }
    };

    int main() {
        Base baseObj;
        Derived derivedObj;

        Base* ptr = &derivedObj; // Pointer to base class pointing to derived object

        baseObj.print();   // Calls Base::print() (static binding)
        derivedObj.print(); // Calls Derived::print() (static binding)
        ptr->print();       // Calls Base::print() (static binding)

        return 0;
    }
    In this example, the print method is not declared as virtual, so the compiler determines which method to call based on the declared type of the object or pointer.

        2. Dynamic Binding :
    Dynamic binding(also known as late binding or runtime polymorphism) occurs when the method to be called is determined at runtime based on the actual type of the object.This is achieved using virtual functions.

       #include <iostream>

        class Base {
        public:
            virtual void print() {
                std::cout << "Base::print()" << std::endl;
            }
    };

    class Derived : public Base {
    public:
        void print() override {
            std::cout << "Derived::print()" << std::endl;
        }
    };

    int main() {
        Base baseObj;
        Derived derivedObj;

        Base* ptr = &derivedObj; // Pointer to base class pointing to derived object

        baseObj.print();   // Calls Base::print()
        derivedObj.print(); // Calls Derived::print()
        ptr->print();       // Calls Derived::print() (dynamic binding)

        return 0;
    }
    In this example, the print method in the base class is declared as virtual, and the derived class overrides it.When calling the method through a pointer to the base class that actually points to a derived object, the method call is resolved at runtime based on the actual type of the object.

        Dynamic binding is a fundamental feature of polymorphism in C++ and allows for more flexible and extensible code.
 */
}

//stupidity to learn this way(as it will make learning OOPS more confusing)
//std::ostream& operator<<(std::ostream& os, const SavingAccount& account) {
//	os << "Saving account balance: " << account.amt << " Interest rate: " << account.interestRate;
//	return os;
//
//}

