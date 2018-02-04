//
// Created by vitaliy on 02.02.18.
//
#include "Functions.h"

int logbase(ull x,ui base)
{
    return int(log(x) / log(base));
}

std::string toBaseLoop(ull x, ui n)
{
    int len = logbase(x, n) + 1;
    std::string res(len, ' ');
    for(int i = len - 1; i > 1; --i)
    {
        ui temp = x % n;
        x /= n;
        if(temp < 10)
            res[i] = '0' + temp;
        else
            res[i] = 'a' + temp - 10;
    }
    ui temp = x % n;
    if(temp < 10)
        res[1] = '0' + temp;
    else
        res[1] = 'a' + temp - 10;

    ui t = x / n;
    if (t < 10)
       res[0] = '0' + t;
    else
       res[0] = 'a' + t - 10;

    return res;
}

std::string toBaseRecursion(ull x, ui n)
{
    if(x > n)
    {
        char res;
        ui temp = x % n;
        if(temp < 10){
            res = '0' + temp;
        }
        else{
            res = 'a' + temp - 10;
        }
        return toBaseRecursion(x / n, n) + res;
    }else {
        ui temp = x / n;
        char res;
        if(temp < 10)
        {
            res = '0' + temp;
        }else{
            res = 'a' + temp - 10;
        }

        return std::string(1, res);
    }

}

unsigned long long inputPositiveData(const std::string& mess, ull max)
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

    if(inputLL <= 0 || inputLL > max){
        return inputPositiveData(mess);
    }

    return inputLL;
}