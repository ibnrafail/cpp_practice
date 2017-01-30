#include "Money.h"


Money::Money(int amount, std::string currency)
{
	this->amount = amount;
	this->currency = currency;
}

Money::~Money()
{
}

Money Money::dollar(MoneyType amount)
{
	return Money(amount, "USD");
}

Money Money::franc(MoneyType amount)
{
	return Money(amount, "CHF");
}
