/**
 * @file Contains implementation of insertion sorting algorithm.
 */
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template<class T>
void showArray(vector<T> &array) {
	cout << "[";
	for (auto i = 0; i < array.size() - 1; i++)
		cout << array[i] << ", ";
	cout << array[array.size() - 1] << "]" << endl;
}

template<class T>
void insertionSort(vector<T> &array) {
	for (auto i = 1; i < array.size(); i++) {
		for (auto j = i - 1; j >= 0; j--) {
			if (array[j+1] < array[j])
			{
				swap(array[j+1], array[j]);
			}
			else break;
		}
	}
}

int main() {
	srand(time(0));
	vector<int> array;

	/** Generating numbers from 1 to 10 */
	for (auto i = 0; i < 10; i++)
		array.push_back(1 + rand() % 10);

	showArray(array);
	insertionSort(array);
	showArray(array);
	return 0;
}
