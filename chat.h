#pragma once

#include "HashTable.h"
#include <string>



class Chat
{
public:
	Chat() = default;
	~Chat();

	void reg(const std::string& login, const std::string& password);
	void login(const std::string& login, const std::string& password);

	void showData();

	void DeleteUserLogin(const std::string& name, const std::string& password);

private:

	HashTable hash_table_;
};

