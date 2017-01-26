/** Contains tests for sorting algorithms from @ref Sortings namespace */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "gtest/gtest.h"
#include "sortingAlgorithms.h"

using namespace std;

class TestSortingsPositive: public ::testing::Test {
public:
	vector<int> input;
	vector<int> expected;
protected:
	virtual void SetUp() {
		expected = Sortings::generate<int>(100);
		input = expected;
		sort(expected.begin(), expected.end());
	}
	virtual void TearDown() {}
};

/**
 * Goes through the given array and checks if each
 * current element > previous element.
 * @param [in] input - vector of elements.
 */
template <class T>
bool checkSortForEach(vector<T> input) {
	int element = input[0];
	for_each(input.begin(), input.end(), [&element](int el) {
		if (el < element)
			return false;
		element = el;
	});
	return true;
}

TEST_F(TestSortingsPositive, testBubbleSortPositive) {
	Sortings::bubbleSort(input);
	EXPECT_FALSE(input.empty());
	EXPECT_TRUE(expected == input);
}

TEST_F(TestSortingsPositive, testSelectionSortPositive) {
	Sortings::selectSort(input);
	EXPECT_FALSE(input.empty());
	EXPECT_TRUE(expected == input);
}

TEST_F(TestSortingsPositive, testInsertionSortPositive) {
	Sortings::insertionSort(input);
	EXPECT_FALSE(input.empty());
	EXPECT_TRUE(expected == input);
}

TEST_F(TestSortingsPositive, testBubbleSortForEach){
	Sortings::bubbleSort(input);
	EXPECT_TRUE(checkSortForEach(input));
}

TEST_F(TestSortingsPositive, testSelectSortForEach) {
	Sortings::selectSort(input);
	EXPECT_TRUE(checkSortForEach(input));
}

TEST_F(TestSortingsPositive, testInsertionSortForEach) {
	Sortings::insertionSort(input);
	EXPECT_TRUE(checkSortForEach(input));
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}