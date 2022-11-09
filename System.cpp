#include "System.h"
#include <iostream>

using namespace std;

std::string System:: getUsername() {
	std::string username;
	cout << "\nUsername: ";
	cin >> username;
	return username;
}

std::string System:: getPass() {
	std::string password;
	cout << "Password: ";
	cin >> password;
	return password;
}

void System::createAccount()
{
	std::string username;
	std::string password;
	double balance;
	std::string ownerName;
	cout << "What is your first name: ";
	cin >> ownerName;
	cout << "Please create a username: ";
	cin >> username;
	cout << "Please create a password: ";
	cin >> password;
	int accNum = accounts.size() + 1;
	cout << "Money to deposit: ";
	cin >> balance;
	Account account(balance, accNum, ownerName, password, username);
	accounts.push_back(account);
}

Account System::login() {
	std::string hasAccount;
	cout << "Do you have an account(Y/N)? ";
	cin >> hasAccount;
	if (hasAccount == "N" || hasAccount == "n")
		createAccount();
	std::string user = getUsername();
	std::string pass = getPass();

	for (Account acc : accounts)
	{
		if (acc.getUsername() == user && acc.getPass() == pass)
			return acc;
	}
	cout << "Invalid Credentials Please Try Again!\n";
	login();
}

void System::run() {
	Account account = login();
	int option;
	double number;
	bool quit = false;
	while (!quit)
	{
	cout << "\nWelcome. Please select your option.\n"
		<< "1. Display Account Information\n"
		<< "2. Display Balance\n"
		<< "3. Deposit Funds\n"
		<< "4. Withdraw Funds\n"
		<< "5. Quit\n"
		<< "Choice: ";
	cin >> option;
	switch(option) {
		case 1:
			cout << "Account Owner Name: " << account.getOwnerName() << "\n"
				<< "Account Number: " <<  account.getAccountNum() << "\n"
				<< "Username: " << account.getUsername() << "\n";
			break;
		case 2:
			cout << "Current balance: $" << account.getBalance() << "\n";
			break;
		case 3:
			cout << "Please specify the amount you wish to add: ";
			cin >> number;
			account.deposit(number);
			cout << "\n$" << number << " has been added to your account. Thank you.";
			break;
		case 4:
			cout << "Please specify the amount you wish to withdraw: ";
			cin >> number;
			account.withdrawl(number);
			cout << "\n$" << number << " has been subtracted from your account. Thank you.";
			break;
		case 5:
			cout << "Thank you. Goodbye.";
				quit = true;
			break;
		}
	}
}