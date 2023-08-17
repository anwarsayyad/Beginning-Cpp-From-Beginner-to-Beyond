#include "Account.h"
#include <iostream>

Account::Account() :amt{ 0.0 } {
	std::cout << "Account Class no-args ctor" << std::endl;
}

Account::Account(double amount) :amt{ amount } {
	std::cout << "Account Class amount-args ctor" << std::endl;
}

void Account::deposit(double amount) {
	amt += amount;
	std::cout << "Deposited in Account: " << amount << " ======= Amount left: " << amt << std::endl;
}
void Account::withdraw(double amount) {
	if (amt - amount > 0) {
		amt -= amount;
		std::cout << "Withdrawal from Account: " << amount << " ======= Amount left: " << amt << std::endl;
	}
	else {
		std::cout << "Couldn't withdraw, Insufficient funds" << " ===== Amount left: " << amt << std::endl;
	}
}
//stupidity to learn this way(as it will make learning OOPS more confusing)
// std::ostream & operator<<(std::ostream & os, const Account & account) {
	//	os << "Account Balance: " << account.amt;
	//	return os;
	//}



