#include "Account.h"

Account::Account(double balance, int accountNum, std::string ownerName, std::string password, std::string username)
{
    this->balance = balance;
    this->accountNum = accountNum;
    this->ownerName = ownerName;
    this->password = password;
    this->username = username;
}
