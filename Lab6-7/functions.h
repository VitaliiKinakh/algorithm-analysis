#pragma once
#include <iostream>

template<class T>
using PREDICATE = bool(*) (T, T);

#pragma region Template Predicates

template <class T>
bool LessThan(T left, T right)
{
	return left < right;
}

template <class T>
bool LessThanOrEqual(T left, T right)
{
	return left <= right;
}

template <class T>
bool GreaterThan(T left, T right)
{
	return left > right;
}

template <class T>
bool GreaterThanOrEqual(T left, T right)
{
	return left >= right;
}

#pragma endregion


#pragma region Sorting_Functions

template <typename T>
void BSort(T array[], long size, PREDICATE<T> funcToCompare)
{
	bool flag = true;
	long i, j;

	T temp;

	for (j = 1;; j++)
	{
		for (i = 0; i < size - j; i++)
			if (!funcToCompare(array[i], array[i + 1]))
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				flag = false;
			}

		if (flag)
			break;

		flag = true;
	}
}


// Quick Sort
template <typename T>
void QSort(T array[], long first, long last, PREDICATE<T> funcToCompare)
{
	if (first < last)
	{
		long i;
		long j;
		T temp;
		T point;

		point = array[first];

		i = first;
		j = last;

		while (i < j)
		{
			while (funcToCompare(array[i], point) && i < last)
				i++;
			while (!funcToCompare(array[j], point) && j > first)
				j--;

			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}


		temp = array[first];
		array[first] = array[j];
		array[j] = temp;

		QSort(array, first, j - 1, funcToCompare);
		QSort(array, j + 1, last, funcToCompare);
	}
}

template <typename T>
void insertionSort(T arr[], int n, PREDICATE<T> funcToCompare)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && funcToCompare(arr[j],key))
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

template<typename T> 
void heapify(T arr[], int n, int i, PREDICATE<T> funcToCompare)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && funcToCompare(arr[l],arr[largest]))
		largest = l;
	if (r < n && funcToCompare(arr[r], arr[largest]))
		largest = r;

	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);

		heapify(arr, n, largest, funcToCompare);
	}
}


template<typename T>
void heapSort(T arr[], int n, PREDICATE<T> funcToCompare)
{
	// Build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i, funcToCompare);
	// Sort
	for (int i = n - 1; i >= 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0, funcToCompare);
	}
}
#pragma endregion

template <typename T>
void PrintArray(T array[], long size)
{
	std::cout << "Array" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}

	std::cout << std::endl << "End" << std::endl;
}
