//
// Created by vitaliy on 27.01.18.
//

#ifndef LAB1_FUNCTIONS_H
#define LAB1_FUNCTIONS_H
#include<iostream>
#include<string>

// Functions definition
long long inputData(const std::string& mess="Enter number: ");

unsigned long long inputPositiveData(const std::string& mess="Enter number: ");

template <typename T>
void showArray(T* array, unsigned long long len)
{
    for(auto i = 0; i < len; ++i)
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
}

bool checkIfSatisfy(long long* array, unsigned long long len);

#endif //LAB1_FUNCTIONS_H
