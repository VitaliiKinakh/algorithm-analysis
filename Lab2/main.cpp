/*
 * Lab 2
 * Taks: Визначити кількість ненульових елементів у кожному непарному рядку матриці
 * G(4,4). Вивести кількість ненульових елементів та номери відповідних рядків.
 * */

// Project directories
#include "Functions.h"

typedef unsigned long long ull;
typedef long double ld;

int main() {
    // Read data
    ull rows = inputPositiveData("Enter number of rows:");
    ull cols = inputPositiveData("Enter number of cols:");

    auto** matrix = new ld*[rows];
    for(auto i = 0; i < rows; ++i)
    {
        matrix[i] = new ld[cols];
    }

    for(int i = 0; i < rows; ++i)
    {
        int numberOfNonZeroElems = 0;
        for(int j = 0; j < cols; ++j)
        {
            matrix[i][j] = inputDoubleData("Enter matrix[" + std::to_string(i) + "][" + std::to_string(j) + "]:");
            if(i % 2 == 1)
            {
                if(matrix[i][j] != 0) ++numberOfNonZeroElems;
            }
        }

        if(i % 2 == 1)
            std::cout << "Non zero elements in row " << i + 1 << " : " << numberOfNonZeroElems << std::endl;
    }


    for(auto i = 0; i < rows; ++i)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}