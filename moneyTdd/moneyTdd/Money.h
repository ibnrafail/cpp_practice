#pragma once
#include <string>

typedef int MoneyType;

class Money
{
	bool compareCurrency(const Money &ob) const { return currency == ob.currency; }
protected:
	MoneyType amount;
	std::string currency;
public:
	Money(int amount, std::string currency);
	~Money();
	bool equals(const Money &ob) const {
		return amount == ob.amount && currency == ob.currency;
	}
	Money operator*(const Money &ob) const {
		return compareCurrency(ob) ? Money(amount * ob.amount, currency) : Money(0, "");
	}
	Money operator+(const Money &ob) const {
		return compareCurrency(ob) ? Money(amount + ob.amount, currency) : Money(0, "");
	}
	bool operator==(const Money &ob) const {
		return amount == ob.amount && currency == ob.currency;
	}
	Money times(MoneyType multiplier) {
		return Money(amount * multiplier, currency);
	}
	Money plus(const Money &ob) const {
		return compareCurrency(ob) ? Money(amount + ob.amount, currency) : Money(0, "");
	}
	virtual std::string getCurrency() { return currency; };
	/** factory methods */
	static Money dollar(MoneyType amount);
	static Money franc(MoneyType amount);
};

