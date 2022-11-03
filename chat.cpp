#include "Chat.h"
#include "Hash.h"
#include <iostream>
#include <string>


Chat::~Chat() {}

void Chat::reg(const std::string& login, const std::string& password)
{
	hash_table_.addData(login, password);
}

void Chat::login(const std::string& login, const std::string& password)
{
	int hash_from_password = hash(password);

	if (hash_table_.getHashByLogin(login) == -1)
	{
		std::cout << "login not found!" << std::endl;
	}
	else if (hash_table_.getHashByLogin(login) == hash_from_password)
	{
		std::cout << "login is succsessful" << std::endl;
	}
	else
	{
		std::cout << "password is not matching!" << std::endl;
	}

}

void Chat::showData()
{
	hash_table_.showCurrentReg();
}

void Chat::DeleteUserLogin(const std::string& login, const std::string& password)
{
	int deletedFlag = hash_table_.Delete(login, password);

	if (deletedFlag == -1)
	{
		std::cout << "delete faild! User login not found" << std::endl;
	}
	else
	{
		std::cout << "User login succsessfully deleted!";
	}

}