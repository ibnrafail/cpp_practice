#include "gtest/gtest.h"
#include "Money.h"
#include "Bank.h"
#include "Expression.h"

TEST(MoneyTC, testMultiplication) {
	EXPECT_TRUE(Money::franc(10).equals(Money::franc(5).times(2)));
	EXPECT_TRUE(Money::franc(15).equals(Money::franc(5).times(3)));
	EXPECT_EQ(Money::dollar(20), Money::dollar(4) * Money::dollar(5));
}

TEST(MoneyTC, testEquality) {
	EXPECT_TRUE(Money::dollar(6).equals(Money::dollar(6)));
	EXPECT_FALSE(Money::dollar(6).equals(Money::dollar(7)));
	EXPECT_TRUE(Money::franc(6) == Money::franc(6));
	EXPECT_FALSE(Money::franc(7) == Money::franc(6));
	EXPECT_FALSE(Money::dollar(10).equals(Money::franc(10)));
}

TEST(MoneyTC, testCurrency) {
	EXPECT_EQ("USD", Money::dollar(10).getCurrency());
	EXPECT_EQ("CHF", Money::franc(10).getCurrency());
}

TEST(MoneyTC, testSimpleAddition) {
	EXPECT_EQ(Money::dollar(10) + Money::dollar(2), Money::dollar(12));
	EXPECT_EQ(Money::dollar(10).plus(Money::dollar(2)), Money::dollar(12));

	Money five = Money::dollar(5);
	Expression sum = five.plus(five);
	Bank bank;
	Money reduced = bank.reduce(sum, "USD");
	ASSERT_EQ(Money::dollar(10), reduced);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}