#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template<class T>
void showArray(vector<T> &array) {
	cout << "[";
	for (size_t i = 0; i < array.size() - 1; i++)
		cout << array[i] << ", ";
	cout << array[array.size() - 1] << "]" << endl;
}

template<class T>
void bubbleSort(vector<T> &array) {
	T temp;
	for (size_t i = array.size() - 1; i > 0; i--) {
		for (size_t j = 0; j < i; j++) {
			if (array[j] > array[j+1])
			{
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}

int main() {
	srand(time(0));
	vector<int> array;

	/** Generating numbers from 1 to 10 */
	for (size_t i = 0; i < 10; i++)
		array.push_back(1 + rand() % 10);

	showArray(array);
	bubbleSort(array);
	showArray(array);

	return 0;
}
