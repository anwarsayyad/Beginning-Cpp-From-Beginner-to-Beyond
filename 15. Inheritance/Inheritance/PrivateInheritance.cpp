#include "PrivateInheritance.h"

#include <iostream>

PrivateInheritance::PrivateInheritance()
//:interestRate{ 4.0 } //not able to initialize like this here because interestRate is not a direct member of PrivateInheritace,  constructor call makes sure the realtionship between PrivateInheritance and SavingAccout is established (As of what I think, it might be wrong)
{
	//interestRate = 4; //after the realtionship is found by the compiler, we can use the SavingAccount's interestRate field
	std::cout << "SavingAccout ctor called" << std::endl;
};
PrivateInheritance:: ~PrivateInheritance()
{
	std::cout << "SavingAccount dtor called" << std::endl;
};

void PrivateInheritance::deposit(double amount) {
	totalamt += amount; //will be not accessible if the class is inherited by two private class in a hierarchy
	std::cout << "Deposited in SavingAccount: " << amount << " Amount left: " << totalamt << std::endl;
}
void PrivateInheritance::withdraw(double amount) {
	totalamt -= amount;
	std::cout << "Withdrawl from SavingAccout" << amount << " Amount left: " << totalamt << std::endl;
}
