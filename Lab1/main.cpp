/*
 * Algorithm analysis lab 1
 * Task: Задано масив S(12). Серед від’ємних парних елементів знайти другий елемент і
 * замінити його максимальним серед додатніх елементів, які мають непарні індекси.
 * Вивести вихідний та перетворений масиви, а також другий елемент серед від’ємних
 * парних елементів та максимальний серед додатніх з непарними індексами
 */

// Project files
#include "Functions.h"

int main() {
    // Create an array
    unsigned long long length = inputPositiveData("Enter length of array:");
    auto *array = new long long[length];
    // Fill an array
    for(unsigned int i = 0; i < length; ++i)
    {
        array[i] = inputData("Enter array[" + std::to_string(i) + "]: ");
    }

    // Check if array satisfy conditions
    // There must be two negative values and one positive
    if(checkIfSatisfy(array, length)) {
        // Find position of second negative value
        unsigned int positionOfSecondEvenNegative;
        unsigned int counterForEvenNegative = 0;
        for (unsigned int i = 0; i < length; ++i) {
            if (array[i] % 2 == 0 && array[i] < 0) {
                ++counterForEvenNegative;
                if (counterForEvenNegative == 2) {
                    positionOfSecondEvenNegative = i;
                    break;
                }
            }
        }

        // Find position of biggest positive value with odd index
        unsigned int positionOfBiggestWithOddIndex;
        long long biggestWithOddIndex = array[0];
        for (unsigned int i = 1; i < length; i += 2) {
            if (array[i] > biggestWithOddIndex && array[i] > 0) {
                biggestWithOddIndex = array[i];
                positionOfBiggestWithOddIndex = i;
            }
        }

        // Show given array
        showArray(array, length);

        // Swap elements
        std::swap(array[positionOfSecondEvenNegative], array[positionOfBiggestWithOddIndex]);
        showArray(array, length);
    }else{
        std::cout << "Your array doesn't satisfy conditions" << std::endl;
    }
    delete [] array;
    return 0;
}