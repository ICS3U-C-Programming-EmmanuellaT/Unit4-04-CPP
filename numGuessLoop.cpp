// Copyright (c) 2026 Emmanuella Taiwo All rights reserved
// Created by: Emmanuella Taiwo
// Date: 17th Nov,2026
// This program asks the for a number between 0 and 9 and
// checks if the input is valid or not.If the input is valid,
// it will display the number back to
// the user in a loop and break and catches errors

#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>

int main() {
    // declare variables
    int userNumber;
    int someRandomNumber;
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    someRandomNumber = idist(rgen);

    // the while true loop
    while (true) {
        // get the number from the user
        std::cout << "Enter a number between 0 and 9: ";
        try {
            if (!(std::cin >> userNumber)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits
                    <std::streamsize>::max(), '\n');
                throw std::invalid_argument
                ("Invalid input. Please enter a valid integer.");
            }

            // check if the number is within the valid range
            if (userNumber < 0 || userNumber > 9) {
                throw std::out_of_range
                ("Invalid input. Please enter a number between 0 and 9.");
            }

            if (userNumber == someRandomNumber) {
                // check if the number is correct
                std::cout << "You are correct!" << std::endl;
                break;
            } else {
                std::cout << "You are wrong. Try again!" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}
