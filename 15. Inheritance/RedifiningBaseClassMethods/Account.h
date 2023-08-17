#pragma once
#include <ostream>

class Account
{
	//friend std::ostream& operator<<(std::ostream& os, const Account& account);
protected:
	double amt;
public:
	Account();
	Account(double amount);
	void deposit(double amount);
	void withdraw(double amount);
	//~Account(); //No need to specify explicitly for our use case, as we are not dealing with any memory management here
};

