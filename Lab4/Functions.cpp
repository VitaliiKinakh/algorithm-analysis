#include"Functions.h"

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


long long binarySearch(const std::vector<long long>& arr, const long long x, const long long l, const long long r)
{
	if (r >= l && r < arr.size())
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}