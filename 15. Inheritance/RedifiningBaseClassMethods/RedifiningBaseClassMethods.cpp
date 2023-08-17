//#include <iostream>
#include <iostream>

#include "Account.h"
#include "SavingAccount.h"
using namespace std;

int main()
{
	Account aadarsh{ 5000 };
	aadarsh.deposit(4000);
	aadarsh.withdraw(10000);

	SavingAccount priya{ 9000,4.0 };
	priya.deposit(4000); //c++ by default uses, "static binding" of method calls (means, it knows that what method to call whether its base class or its own)
	priya.withdraw(1000);
}

//another example of "static binding"
//Base* ptr = new Derived();
//ptr->deposit(1000.0);//this will deposit into Base class(not in Derived class), but in this case its better to use "Dynamic binding" because it makes more sense 


