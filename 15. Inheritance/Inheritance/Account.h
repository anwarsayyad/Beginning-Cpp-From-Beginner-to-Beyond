#pragma once
class Account
{
private:
	double totalamt{};
public:
	void deposit(double amount);
	void withdraw(double amount);

	Account();
	~Account();
};

