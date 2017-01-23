#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "sortingAlgorithms.h"

using namespace std;

template<class T>
vector<T> generate(int arraySize) {
	vector<T> array;
	for (size_t i = 0; i < arraySize; i++)
		array.push_back(1 + rand() % arraySize);
	return array;
}

int main() {
	srand(time(0));
	cout << "Bubble sort." << endl;
	vector<int> array = generate<int>(10);
	showArray(array);
	bubbleSort(array);
	showArray(array);

	cout << "Insertion sort." << endl;
	array = generate<int>(10);
	showArray(array);
	insertionSort(array);
	showArray(array);

	cout << "Selection sort." << endl;
	array = generate<int>(10);
	showArray(array);
	selectSort(array);
	showArray(array);
	return 0;
}
