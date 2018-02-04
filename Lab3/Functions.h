//
// Created by vitaliy on 02.02.18.
//

#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include <string>
#include <cmath>
#include <iostream>
#include <climits>

typedef unsigned long long ull;
typedef unsigned int ui;

//  x - number for convertion
//  n - base from 2 to 36 due to number of characters
std::string toBaseLoop(ull x, ui n);

std::string toBaseRecursion(ull x, ui n);

int logbase(ull x, ui base);

ull inputPositiveData(const std::string& mess, ull max=LLONG_MAX);

#endif //LAB3_FUNCTIONS_H
