#include "SavingAccount.h"

#include <iostream>

/*SavingAccount::SavingAccount() :interestRate{ 3.0 }, Account{ 4000.33 } {
	std::cout << "SavingAccout ctor called" << std::endl;
}*/;
SavingAccount::SavingAccount() :interestRate{ 3.0 } {
	std::cout << "SavingAccout ctor called" << std::endl;
};


SavingAccount::~SavingAccount() {
	std::cout << "SavingAccount dtor called" << std::endl;
};

void SavingAccount::deposit(double amount) {
	totalamt += amount; //will be accessible if Account::totalamt is declared as protected/public
	std::cout << "Deposited in SavingAccount: " << amount << " Amount left: " << totalamt << std::endl;
}
void SavingAccount::withdraw(double amount) {
	totalamt -= amount;
	std::cout << "Withdrawl from SavingAccout" << amount << " Amount left: " << totalamt << std::endl;
}
