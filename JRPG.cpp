#include <iostream>
#include <string>
#include <cctype>


using namespace std;

int getValidatedInput(int minRange, int maxRange) {
    string input;
    int number;

    while (true) {
        cout << "Enter a number between " << minRange << " and " << maxRange << ": ";
        cin >> input;

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

        cout << "Invalid input. Try again.\n";
    }
}

