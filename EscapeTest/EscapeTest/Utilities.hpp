#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <random>
#include <string>
#include <iostream>

inline int ranNumGen(int minRange, int maxRange) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(minRange, maxRange);
    int ranNum = dist(gen);
    return ranNum;
}

inline int getValidatedInput(int minRange, int maxRange) {
    std::string input;
    int number;

    while (true) {
        std::cout << "Enter a number between " << minRange << " and " << maxRange << ": ";
        std::cin >> input;

        // Check if all characters in input are digits
        bool isNumber = true;
        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }

        // Convert to int and validate range
        if (isNumber && input.length() <= 2) {
            number = stoi(input);
            if (number >= minRange && number <= maxRange) {
                return number;
            }
        }

        std::cout << "Invalid input. Try again.\n";
    }
}

#endif