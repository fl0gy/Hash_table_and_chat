#include "HashTable.h"
#include "Hash.h"
#include <iostream>

HashTable::HashTable()
{
	data_count_ = 0;
	mem_size_ = 8;
	data_array_ = new Pair[mem_size_];
}

HashTable::~HashTable()
{
	delete[] data_array_;
}

int HashTable::hashFuncQprobe(const std::string login, int offset)
{
	int sum = 0;

	for (int i = 0; i < login.size(); i++)
	{
		sum += login[i];
	}

	return (sum % mem_size_ + offset * offset) % mem_size_;
}

void HashTable::addData(const std::string& login, const std::string& password)
{
	int index = -1, i = 0;

	if (mem_size_ == data_count_)
	{
		resize();
	}

	for (; i < mem_size_; i++)
	{
		index = hashFuncQprobe(login, i);

		if (data_array_[index].status_ != PairStatus::engaged)
		{
			break;
		}
	}
	if (i >= mem_size_) return;

	int hash_from_password = hash(password);
	data_array_[index] = Pair(login, hash_from_password);
	data_count_++;

}

int HashTable::getHashByLogin(const std::string& login)
{
	int index = -1;

	for (int i = 0; i < mem_size_; i++)
	{
		index = hashFuncQprobe(login, i);

		if (data_array_[index].login_ == login)
		{
			return data_array_[index].hash_;
		}
	}

	return -1;

}

void HashTable::showCurrentReg()
{
	for (int i = 0; i < mem_size_; i++)
	{
		std::cout << "login  : " << data_array_[i].login_ << std::endl;
		std::cout << "hash   : " << data_array_[i].hash_ << std::endl;
		std::cout << "status : " << data_array_[i].status_ << std::endl;
		std::cout << std::endl;
	}
	std::cout << "number of users registered : " << data_count_ << std::endl;
	std::cout << std::endl;
}

void HashTable::resize()
{
	mem_size_ += 1;

	Pair* newPair = new Pair[mem_size_];

	for (int i = 0; i < mem_size_ - 1; i++) // copying old data 
	{
		newPair[i] = data_array_[i];
	}
	delete[] data_array_;
	data_array_ = newPair;

}

int HashTable::Delete(const std::string& login, const std::string& password)
{
	int index = -1;

	for (int i = 0; i < mem_size_; i++)
	{
		index = hashFuncQprobe(login, i);

		if (data_array_[index].login_ == login)
		{
			data_array_[index].status_ = deleted;
			data_array_[index].login_ = "deleted";
			data_array_[index].hash_ = 0;
			data_count_--;
			return i;
		}
	}
	return -1;
}