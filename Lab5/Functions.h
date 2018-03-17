#pragma once
#include<string>
#include<iostream>
#include<vector>

long long inputData(const std::string& mess = "Enter number: ");

unsigned long long inputPositiveData(const std::string& mess = "Enter positive number: ");

long long partition(std::vector<long long> arr, int l, int r);

long long kthSmallest(std::vector<long long> arr, int l, int r, int k);