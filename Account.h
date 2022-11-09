#pragma once
#include <string>

class Account
{
private:
	double balance;
	int accountNum;
	std::string ownerName;
	std::string password;
	std::string username;

public:
    // Constructor
    Account() : balance(0.00), accountNum(0), ownerName("default"), password("password"), username("user") {}
    Account(double balance, int accountNum, std::string ownerName, std::string password, std::string username);

    // Getters
	double getBalance() { return balance; }
	int getAccountNum() { return accountNum; }
	std::string getOwnerName() { return ownerName; }
	std::string getPass() { return password; }
	std::string getUsername(){ return username; }

	void deposit(double number) { balance += number; }
	void withdrawl(double number) { balance -= number; }
};

