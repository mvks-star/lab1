#pragma once
#include <iostream>
#include <cctype>

using namespace std;

inline int ReadNonNegativeInt() {
    int number;
    while (true) {
        if (cin >> number && number >= 0) {
            return number;
        }
        cout << "Invalid input! Enter a non-negative integer: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

inline void ReadLettersOnly(char* buffer) {
    while (true) {
        cin >> buffer;
        bool isValid = true;

        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isalpha(buffer[i])) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            return;
        }
        cout << "Invalid input! Use letters only: ";
    }
}