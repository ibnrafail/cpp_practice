#pragma once
#include "Money.h"
#include "Expression.h"
#include <string>

class Bank
{
public:

	Bank()
	{
	}

	~Bank()
	{
	}
	Money reduce(Expression expr, std::string)
	{
		return Money(10, "USD");
	}
};

