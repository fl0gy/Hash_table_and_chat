#pragma once
#include <string>

class HashTable
{
public:
	HashTable();
	~HashTable();

	void addData(const std::string& login, const std::string& password);

	int getHashByLogin(const std::string& login);
	void resize();
	int Delete(const std::string& login, const std::string& password);

	void showCurrentReg(); // display to console all users info


private:
	enum PairStatus
	{
		free, engaged, deleted
	};

	struct Pair
	{
		Pair() : hash_(0) { status_ = PairStatus::free; }

		Pair(std::string login, int hash) :
			login_(login), hash_(hash) {
			status_ = engaged;
		}

		Pair& operator = (const Pair& other)
		{
			login_ = other.login_;
			hash_ = other.hash_;
			status_ = other.status_;

			return *this;
		}

		std::string login_;
		int hash_;

		PairStatus status_;

	};

	int hashFuncQprobe(std::string login, int offset);

	Pair* data_array_;
	int mem_size_;
	int data_count_;
};

