//
// Created by vitaliy on 27.01.18.
//
#include"Functions.h"

// Function realisation

long long inputData(const std::string& mess)
{
    std::cout << mess << std::endl;
    std::string inputString;
    std::cin >> inputString;
    long long inputLL;
    try {
        inputLL = std::stoll(inputString);
    }catch(const std::invalid_argument& ia){
        std::cerr << "Invalid argument" << std::endl;
        return inputData(mess);
    }catch(const std::out_of_range& oor){
        std::cerr << "Out of range argument" << std::endl;
        return inputData(mess);
    }catch(...){
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
    }catch(const std::invalid_argument& ia){
        std::cerr << "Invalid argument" << std::endl;
        return inputData(mess);
    }catch(const std::out_of_range& oor){
        std::cerr << "Out of range argument" << std::endl;
        return inputData(mess);
    }catch(...){
        std::cerr << "Something went wrong" << std::endl;
        return inputData(mess);
    }

    if(inputLL <= 0){
        return inputData(mess);
    }

    return inputLL;
}


bool checkIfSatisfy(long long* array, unsigned long long len)
{
    unsigned int numberOfEvenNegativeValues = 0;
    unsigned int numberOfPositiveValuesWithOddIndexes = 0;
    for(auto i = 0; i < len; ++i)
    {
        if(array[i] % 2 == 0 && array[i] < 0)
        {
            ++numberOfEvenNegativeValues;
        }
        if(i % 2 == 1 && array[i] > 0)
        {
            ++numberOfPositiveValuesWithOddIndexes;
        }
        if(numberOfEvenNegativeValues >= 2 && numberOfPositiveValuesWithOddIndexes >= 1)
            return true;
    }

    return (numberOfEvenNegativeValues >= 2 && numberOfPositiveValuesWithOddIndexes >= 1);
}