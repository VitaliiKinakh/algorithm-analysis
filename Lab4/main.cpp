/*
*	Lab4 
*   create binary search algorithm recursion
*/

#include<iostream>
#include<algorithm>

#include"Functions.h"

int main()
{
	long long len = inputData("Enter lenght of array: ");
	std::vector<long long> arr;

	// sort an array
	std::sort(arr.begin(), arr.end());
	
	for (int i = 0; i < len; ++i)
	{
		long long element = inputData("Enter arr[" + std::to_string(i) + "]: ");
		arr.push_back(element);
	}

	long long find = inputData("Enter element for findong: ");

	long long pos = binarySearch(arr, find, 0, len);

	std::cout << "Sorted array" << std::endl;
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	if (pos != -1) {
		std::cout << "Element " << find << " was founded at position " << pos << std::endl;
	}
	else {
		std::cout << "Element " << find << " is not present in the array" << std::endl;
	}

	return 0;
}