#include "Account.h"

#include <iostream>

void Account::deposit(double amount) {
	totalamt += amount;
	std::cout << "Deposited in base Account: " << amount << " Amt left: " << totalamt << std::endl;
}
void Account::withdraw(double amount) {
	totalamt -= amount;
	std::cout << "Withdrawl from base Account" << amount << " Amt left: " << totalamt << std::endl;
}

Account::Account() :totalamt{ 0.0 } {
	std::cout << "no-args ctor" << std::endl;
}
Account::~Account() {
	std::cout << "destructed" << std::endl;
}
