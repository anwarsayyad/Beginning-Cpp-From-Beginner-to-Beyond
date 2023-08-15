#include "SavingAccount.h"

#include <iostream>

SavingAccount::SavingAccount() :interestRate{ 3.0 } {
	std::cout << "SavingAccout ctor called" << std::endl;
};

SavingAccount::~SavingAccount() {
	std::cout << "SavingAccount dtor called" << std::endl;
};

void SavingAccount::deposit(double amount) {

	std::cout << "Deposited in SavingAccount: " << amount << std::endl;
}
void SavingAccount::withdraw(double amount) {
	std::cout << "Withdrawl from SavingAccout" << amount << std::endl;
}
