//
// Created by vitaliy on 30.01.18.
//
#include "Functions.h"

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
        return inputPositiveData(mess);
    }catch(const std::out_of_range& oor){
        std::cerr << "Out of range argument" << std::endl;
        return inputPositiveData(mess);
    }catch(...){
        std::cerr << "Something went wrong" << std::endl;
        return inputPositiveData(mess);
    }

    if(inputLL <= 0){
        return inputPositiveData(mess);
    }

    return inputLL;
}


long double inputDoubleData(const std::string& mess)
{

    std::cout << mess << std::endl;
    std::string inputString;
    std::cin >> inputString;
    long double inputLD;
    try {
        inputLD = std::stod(inputString);
    }catch(const std::invalid_argument& ia){
        std::cerr << "Invalid argument" << std::endl;
        return inputDoubleData(mess);
    }catch(const std::out_of_range& oor){
        std::cerr << "Out of range argument" << std::endl;
        return inputDoubleData(mess);
    }catch(...){
        std::cerr << "Something went wrong" << std::endl;
        return inputDoubleData(mess);
    }
    return inputLD;
}