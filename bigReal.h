#include <iostream>
#include <deque>
#include <regex>
using namespace std;

// Function declarations
void makeEqualAtFront(deque<int> &a, deque<int> &b);
void makeEqualAtBack(deque<int> &A, deque<int> &B);
string subtraction(string num1, string num2);
string addition(string num1, string num2);

// Class definition for handling big real numbers
class bigReal {
private:
    string number;     // Integer part of the big real number
    char sign{};       // Sign of the big real number ('+' or '-')
    string fraction;    // Fractional part of the big real number
    string allNumber;   // Complete representation of the big real number (integer + fraction)

    // Private static method to check if a string is a valid representation of a real number
    static bool isValidReal(const string &input);

public:
    // Constructors
    bigReal() = default;
    explicit bigReal(string n);

    // Member functions
    void setNumber(const string &n);    // Set the value of the big real number
    string getNumber();                  // Get the value of the big real number
    char Sign();                         // Get the sign of the big real number
    int Size();                          // Get the size of the big real number (total digits)

    // Overloaded operators
    friend istream& operator >> (istream& fs, bigReal &n);   // Overloaded input operator
    friend ostream &operator << (ostream &os, const bigReal &n);  // Overloaded output operator
    bigReal operator + (bigReal n2);    // Overloaded addition operator
    bigReal operator - (bigReal n2);    // Overloaded subtraction operator

    // Comparison operators
    bool operator > (bigReal n2);      // Overloaded greater than operator
    bool operator < (bigReal n2);      // Overloaded less than operator
    bool operator == (bigReal n2);     // Overloaded equality operator
};