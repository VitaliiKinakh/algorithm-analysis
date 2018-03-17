#include "Functions.h"

long long inputData(const std::string& mess)
{
	std::cout << mess << std::endl;
	std::string inputString;
	std::cin >> inputString;
	long long inputLL;
	try {
		inputLL = std::stoll(inputString);
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument" << std::endl;
		return inputData(mess);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of range argument" << std::endl;
		return inputData(mess);
	}
	catch (...) {
		std::cerr << "Something went wrong" << std::endl;
		return inputData(mess);
	}
	return inputLL;
}

unsigned long long inputPositiveData(const std::string& mess)
{
	std::cout << mess << std::endl;
	std::string inputString;
	std::cin >> inputString;
	long long inputLL;
	try {
		inputLL = std::stoll(inputString);
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument" << std::endl;
		return inputData(mess);
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of range argument" << std::endl;
		return inputData(mess);
	}
	catch (...) {
		std::cerr << "Something went wrong" << std::endl;
		return inputData(mess);
	}

	if (inputLL > 0)
	{
		return inputLL;
	}
	else {
		std::cerr << "Enter possitive data: " << std::endl;
		return inputData(mess);
	}
}


long long kthSmallest(std::vector<long long> arr, int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int pos = partition(arr, l, r);

		if (pos - l == k - 1)
			return arr[pos];
		if (pos - l > k - 1)
			return kthSmallest(arr, l, pos - 1, k);

		return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
	}

	return INT_MAX;
}

long long partition(std::vector<long long> arr, int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			std::swap(arr[i], arr[j]);
			i++;
		}
	}
	std::swap(arr[i], arr[r]);
	return i;
}