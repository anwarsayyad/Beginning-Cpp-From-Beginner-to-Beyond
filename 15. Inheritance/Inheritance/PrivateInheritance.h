#pragma once
#include <string>

#include "SavingAccount.h"
class PrivateInheritance :
	private SavingAccount
{
private:
	std::string name;
public:
	void deposit(double amount);
	void withdraw(double amount);
	PrivateInheritance();
	~PrivateInheritance();
};

