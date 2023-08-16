#pragma once

class Account
{
protected:
	double totalamt{};
public:
	void deposit(double amount);
	void withdraw(double amount);

	Account();
	//Account(double interestRate);
	~Account();
};

