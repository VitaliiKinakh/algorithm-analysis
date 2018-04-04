#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include "functions.h"

int main()
{
	srand(time(0));

	const int len = 10000;
	long long arr[len];
	/* Fill an array */

	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand();
	}

	PrintArray(arr, len);

	heapSort(arr, len, GreaterThanOrEqual);
	
	PrintArray(arr, len);
	return 0;
}