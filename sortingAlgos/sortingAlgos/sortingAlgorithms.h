#pragma once
/** @file Contains implementation of different sorting algorithms. */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

namespace Sortings {
	/**
	 * Generates array of @ref arraySize size.
	 * @param [in] arraySize - size of final vector.
	 */
	template<class T>
	std::vector<T> generate(size_t arraySize) {
		vector<T> array;
		for (size_t i = 0; i < arraySize; i++)
			array.push_back(1 + rand() % arraySize);
		return array;
	}

	/**
	 * Prints @ref std::vector<T> to stdout.
	* @param array - array based on std::vector.
	 */
	template<class T>
	void showArray(std::vector<T> array) {
		std::cout << "[";
		for_each(array.begin(), array.end(), [](T e) {std::cout << e << ", "; });
		std::cout << array[array.size() - 1] << "]" << std::endl;
	}

	/**
	 * Sorts @ref std::vector<T> using bubble sorting algo.
	 * @param array - array based on std::vector.
	 */
	template<class T>
	void bubbleSort(std::vector<T> &array) {
		T temp;
		for (size_t i = array.size() - 1; i > 0; i--) {
			for (size_t j = 0; j < i; j++) {
				if (array[j] > array[j + 1]) {
					std::swap(array[j], array[j + 1]);
				}
			}
		}
	}

	/**
	 * Sorts @ref std::vector<T> using insertion sorting algo.
	 * @param array - array based on std::vector.
	*/
	template<class T>
	void insertionSort(std::vector<T> &array) {
		for (auto i = 1; i < array.size(); i++) {
			for (auto j = i - 1; j >= 0; j--) {
				if (array[j + 1] < array[j])
				{
					std::swap(array[j + 1], array[j]);
				}
				else break;
			}
		}
	}

	/**
	 * Sorts @ref std::vector<T> using selection sorting algo.
	 * @param array - array based on std::vector.
	*/
	template<class T>
	void selectSort(std::vector<T> &array) {
		T min;
		size_t indMin;
		for (auto i = 0; i < array.size(); i++) {
			min = array[i]; indMin = i;
			for (auto j = i + 1; j < array.size(); j++) {
				if (array[j] < min) {
					min = array[j];
					indMin = j;
				}
			}
			if (indMin != i) {
				std::swap(array[i], array[indMin]);
			}
		}
	}
} /** namespace Sortings */