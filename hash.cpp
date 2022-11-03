#include "Hash.h"

int hash(const std::string& password)
{
	const double A = 0.7;
	const int M = 100;
	int val = 0;

	for (int i = 0; i < password.size(); i++)
	{
		val += password[i];
	}

	return int(M * (A * val - int(A * val)));
}