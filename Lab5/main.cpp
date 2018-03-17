#include<iostream>
#include<vector>
#include<algorithm>

#include"Functions.h"

typedef unsigned long long ull;

int main()
{
	ull len = inputPositiveData("Enter lenght of array: ");
	std::vector<long long> arr;
	std::vector<bool> map;
	for (int i = 0; i < len; ++i)
	{
		long long temp = inputData("Enter element["  + std::to_string(i) + "]: ");
		arr.push_back(temp);
		map.push_back(1);
	}

	ull pos = inputPositiveData("Enter k: ");
	
	if (pos < len) {
		std::cout << pos << " element is " << kthSmallest(arr, 0, len - 1, pos) << std::endl;
	}
	else {
		std::cerr << "Invalid position" << std::endl;
	}
	
	return 0;
}