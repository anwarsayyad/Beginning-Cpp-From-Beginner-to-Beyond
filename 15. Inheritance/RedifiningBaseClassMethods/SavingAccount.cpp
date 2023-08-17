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
	Account::deposit(amount); //using the Base class, this is also called as "Dynamic binding"
}

//stupidity to learn this way(as it will make learning OOPS more confusing)
//std::ostream& operator<<(std::ostream& os, const SavingAccount& account) {
//	os << "Saving account balance: " << account.amt << " Interest rate: " << account.interestRate;
//	return os;
//
//}

