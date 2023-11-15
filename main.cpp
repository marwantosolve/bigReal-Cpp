// File: main.cpp
// Purpose: A program using the bigReal class to perform operations on very large real numbers
// Author: Marwan Osama
// Section: S17,18
// ID: 20220324
// TA: Rana Abdelkader
// Date: 15 Nov 2023

#include <iostream>
#include "BigReal.cpp"
using namespace std;

int main() {
    // Declare variables to store user input
    string n1, n2;

    // Get the first number from the user
    cout << "Enter the first number: \n"
            ">> ";
    cin >> n1;

    // Display separator
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // Get the second number from the user
    cout << "Enter the second number: \n"
            ">> ";
    cin >> n2;

    // Display separator
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // Create bigReal objects based on user input
    bigReal b1(n1), b2(n2);

    // Display menu options
    cout << "(1) n1 + n2 \n"
            "(2) n1 - n2 \n"
            "(3) Compare (n1 , n2) \n";

    // Display separator
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    // Variable to store user's operation choice
    string op;

    // Main loop to keep the program running until the user decides to exit
    while (true) {
        // Prompt user to select an option
        cout << "Select an option from the menu to apply: \n"
                ">> ";
        cin >> op;

        // Perform the selected operation based on user input
        if (op == "1") {
            // Addition operation
            bigReal sum;
            sum = b1 + b2;
            // Display the result
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << sum << '\n';
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        } else if (op == "2") {
            // Subtraction operation
            bigReal diff = b1 - b2;
            // Display the result
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << diff << '\n';
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        } else if (op == "3") {
            // Comparison operation
            if (b1 > b2) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "n1 is greater than n2 ! \n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            } else if (b1 < b2) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "n1 is less than n2 ! \n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            } else if (b1 == b2) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "n1 is equal to n2 ! \n";
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            }
        } else if (op == "0") {
            // Exit the program
            return 0;
        }
    }
}