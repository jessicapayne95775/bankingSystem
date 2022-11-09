#pragma once

#include "Account.h"
#include <string>
#include <list>

class System
{
private:
	std::list<Account> accounts;
public:
	void run();
	std::string getUsername();
	std::string getPass();
	void createAccount();
	Account login();
};

