#pragma once
#include "Account.h"

class SavingAccount :
	public Account //public inheritance,
	//public- establishes "is-a" relationship between derived and base class
	//private and protected(NOTE: not covered in this course, learn it on your own[maybe from chaptgpt :)])- establishes "has-a" relationship between derived and base class
{
private:
	double interestRate{};
public:
	SavingAccount();
	~SavingAccount();
	void deposit(double amount);
	void withdraw(double amount);
};

