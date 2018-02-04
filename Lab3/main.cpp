#include <iostream>

/* Lab 3
 * Task: Перевести десяткове число в n-ту систему числення
 */

#include "Functions.h"

int main() {
    ull number = inputPositiveData("Enter number to be converted");
    ui base = inputPositiveData("Enter base in range [0, 36]", 36);

    std::string convertedLoop = toBaseLoop(number, base);
    std::cout << "Result using loop algorithm " << convertedLoop << std::endl;

    std::string convertedRecursive = toBaseRecursion(number, base);
    std::cout << "Result using recursive algorithm " << convertedRecursive << std::endl;
    return 0;
}