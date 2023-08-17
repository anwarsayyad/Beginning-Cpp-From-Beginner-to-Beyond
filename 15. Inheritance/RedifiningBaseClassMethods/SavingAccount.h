#pragma once
#include "Account.h"
class SavingAccount :
	public Account
{
	//friend std::ostream& operator <<(std::ostream& os, const SavingAccount& account);
protected:
	double interestRate;
public:
	SavingAccount();
	SavingAccount(double amount, double interestRate);
	void deposit(double amount); //overwriting the Account::deposit
	//we will not need to implement new withdraw, we can use the inherited Account::withdraw method
};

