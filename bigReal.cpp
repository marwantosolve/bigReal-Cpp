#include "bigReal.h"

// Function to make the number of digits at the front of two deques equal
void makeEqualAtFront(deque<int> &a, deque<int> &b) {
    int n = a.size();
    int m = b.size();
    int diff = abs(n - m);

    // If the first deque is smaller, insert zeros at the front to make sizes equal
    if (n < m) {
        for (int i = 0; i < diff; i++) {
            a.insert(a.begin(), 0);
        }
    } else { // If the second deque is smaller, insert zeros at the front to make sizes equal
        for (int i = 0; i < diff; i++) {
            b.insert(b.begin(), 0);
        }
    }
}
// Function to make the number of digits at the back of two deques equal
void makeEqualAtBack(deque<int> &a, deque<int> &b) {
    int n = a.size();
    int m = b.size();
    int diff = abs(n - m);

    // If the first deque is smaller, append zeros at the back to make sizes equal
    if (n < m) {
        for (int i = 0; i < diff; i++) {
            a.push_back(0);
        }
    } else { // If the second deque is smaller, append zeros at the back to make sizes equal
        for (int i = 0; i < diff; i++) {
            b.push_back(0);
        }
    }
}
// Function to perform subtraction of two decimal numbers represented as strings
string subtraction(string n1, string n2) {
    int i;
    string res;
    deque<int> int1, int2; // Deques to store integer parts
    deque<int> fr1, fr2;   // Deques to store fractional parts

    // Extract fractional part of the first number and store it in reverse order
    for (i = n1.length() - 1; i > -1; i--) {
        if (n1[i] == '.') {
            break;
        }
        fr1.push_back(n1[i] - '0');
    }

    i--;
    // Extract integer part of the first number and store it in reverse order
    for (; i > -1; i--) {
        int1.push_back(n1[i] - '0');
    }

    // Extract fractional part of the second number and store it in reverse order
    for (i = n2.length() - 1; i > -1; i--) {
        if (n2[i] == '.') {
            break;
        }
        fr2.push_back(n2[i] - '0');
    }

    i--;
    // Extract integer part of the second number and store it in reverse order
    for (; i > -1; i--) {
        int2.push_back(n2[i] - '0');
    }

    // Make the fractional parts and integer parts of both numbers equal in size
    makeEqualAtFront(fr1, fr2);
    makeEqualAtBack(int1, int2);

    // Subtraction logic for fractional parts
    int n = fr1.size();
    int m = fr2.size();
    i = 0;
    int carry = 0;

    while (i < n && i < m) {
        int sum = fr1[i] - fr2[i] + carry;
        if (sum < 0) {
            carry = -1;
            fr1[i] = (10 + sum) % 10;
        } else {
            fr1[i] = sum % 10;
            carry = sum / 10;
        }
        i++;
    }

    // Subtraction logic for integer parts
    int N = int1.size();
    int M = int2.size();
    i = 0;

    while (i < N && i < M) {
        int sum = int1[i] - int2[i] + carry;
        if (sum < 0) {
            carry = -1;
            int1[i] = (10 + sum) % 10;
        } else {
            int1[i] = sum % 10;
            carry = sum / 10;
        }
        i++;
    }

    // Convert the result back to string
    for (int i = int1.size() - 1; i > -1; i--) {
        res += to_string(int1[i]);
    }
    res += '.';
    for (int i = fr1.size() - 1; i > -1; i--) {
        res += to_string(fr1[i]);
    }
    return res;
}
// Function to perform addition of two decimal numbers represented as strings
string addition(string n1, string n2) {
    int i;
    string res;
    deque<int> Ints1, Ints2;   // Deques to store integer parts
    deque<int> Fracs1, Fracs2; // Deques to store fractional parts

    // Extract fractional part of the first number and store it in reverse order
    for (i = n1.length() - 1; i > -1; i--) {
        if (n1[i] == '.') {
            break;
        }
        Fracs1.push_back(n1[i] - '0');
    }

    i--;
    // Extract integer part of the first number and store it in reverse order
    for (; i > -1; i--) {
        Ints1.push_back(n1[i] - '0');
    }

    // Extract fractional part of the second number and store it in reverse order
    for (i = n2.length() - 1; i > -1; i--) {
        if (n2[i] == '.') {
            break;
        }
        Fracs2.push_back(n2[i] - '0');
    }

    i--;
    // Extract integer part of the second number and store it in reverse order
    for (; i > -1; i--) {
        Ints2.push_back(n2[i] - '0');
    }

    // Make the fractional parts and integer parts of both numbers equal in size
    makeEqualAtFront(Fracs1, Fracs2);
    makeEqualAtBack(Ints1, Ints2);

    // Addition logic for fractional parts
    int n = Fracs1.size();
    int m = Fracs2.size();
    i = 0;
    int carry = 0;

    while (i < n && i < m) {
        int sum = Fracs1[i] + Fracs2[i] + carry;
        Fracs1[i] = sum % 10;
        carry = sum / 10;
        i++;
    }

    // Addition logic for integer parts
    int N = Ints1.size();
    int M = Ints2.size();
    i = 0;

    while (i < N && i < M) {
        int sum = Ints1[i] + Ints2[i] + carry;
        Ints1[i] = sum % 10;
        carry = sum / 10;
        i++;
    }

    // If there is a remaining carry after adding the integer parts, append it
    if (carry != 0)
        Ints1.push_back(carry);

    // Convert the result back to string
    for (int i = Ints1.size() - 1; i > -1; i--) {
        res += to_string(Ints1[i]);
    }
    res += '.';
    for (int i = Fracs1.size() - 1; i > -1; i--) {
        res += to_string(Fracs1[i]);
    }
    return res;
}

// Member functions
// Constructor for the bigReal class, taking a string as input
bigReal::bigReal(string n) {
    // Set the internal representation of the number
    setNumber(n);

    // Initialize the index for iterating through the input string
    int i = 0;

    // Check the sign of the number
    if (n[0] == '-') {
        sign = '-';
        i++;
    } else if (n[0] == '+') {
        sign = '+';
        i++;
    } else {
        // If no sign is provided, default to positive
        sign = '+';
    }

    // Extract the integral part of the number
    for (; i < n.length(); i++) {
        if (n[i] == '.') {
            break;
        }
        // Add each character to the integral part
        allNumber.push_back(n[i]);
    }

    // Move past the decimal point
    i++;

    // Extract the fractional part of the number
    for (; i < n.length(); i++) {
        // Add each character to the fractional part
        fraction.push_back(n[i]);
    }
}
// Function to set the internal number representation, called by the constructor
void bigReal::setNumber(const string &n) {
    // Check if the input string is a valid real number
    bool validNumber = isValidReal(n);
    if (validNumber) {
        // Set the internal number representation
        number = n;

        // Check and set the sign of the number
        if (number[0] == '+') {
            number.erase(0, 1);
            sign = '+';
        } else if (number[0] == '-') {
            number.erase(0, 1);
            sign = '-';
        } else {
            // If no sign is provided, default to positive
            sign = '+';
        }
    } else {
        // If the input is not a valid real number, print an error message and exit
        cout << "Invalid real number" << endl;
        exit(1);
    }
}
// Function to retrieve the internal number representation
string bigReal::getNumber() {
    return number;
}
// Function to check if a given string is a valid real number using regular expressions
bool bigReal::isValidReal(const std::string &input) {
    regex validInput("[+-]?([0-9]*[.])?[0-9]+");
    return regex_match(input, validInput);
}
// Function to retrieve the sign of the number
char bigReal::Sign() {
    return sign;
}
// Function to get the total number of digits in the number (both integral and fractional parts)
int bigReal::Size() {
    return fraction.length() + allNumber.length();
}

// Overloaded operators
// Overloaded >> (input) operator for the bigReal class
istream &operator>>(istream &fs, bigReal &n) {
    // Read a string from the input stream
    string s;
    fs >> s;

    // Create a temporary bigReal object using the input string
    bigReal temp(s);

    // Assign the temporary object to the input parameter
    n = temp;

    // Return the input stream for possible chaining
    return fs;
}
// Overloaded << (output) operator for the bigReal class
ostream &operator<<(ostream &os, const bigReal &n) {
    // Check the sign of the number
    if (n.sign == '+') {
        // If positive, output the number directly
        os << n.number;
    } else {
        // If negative, check if the number is zero
        if (n.number == "0") {
            // If zero, output the number directly
            os << n.number;
        } else {
            // If non-zero, output the sign and the number
            os << n.sign << n.number;
        }
    }

    // Return the output stream for possible chaining
    return os;
}
// Overloaded addition operator for bigReal class
bigReal bigReal::operator+(bigReal n2) {
    // Initialize variables
    char signNumber1 = sign, signNumber2 = n2.sign;
    string num1 = number, num2 = n2.number;
    bigReal n1 = *this;
    bigReal result;

    // Ensure the numbers have the same length by adding leading zeros
    while (num1.length() < num2.length()) {
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length()) {
        num2 = '0' + num2;
    }

    // Check the signs of the numbers for addition
    if (signNumber1 == signNumber2) {
        // If signs are the same, result takes the sign of the numbers, and perform addition
        result.sign = signNumber1;
        result.number = addition(num1, num2);
    } else {
        // If signs are different, convert subtraction to addition
        if (n1.sign == '-') {
            n1.sign = '+';
            result = (n2 - n1);
        } else {
            n2.sign = '+';
            result = (n1 - n2);
        }
    }

    // Return the result of addition
    return result;
}
// Overloaded subtraction operator for bigReal class
bigReal bigReal::operator-(bigReal n2) {
    // Initialize variables
    string strmin = "", res = "";
    string num1 = number, num2 = n2.number;
    char sign1 = sign, sign2 = n2.sign;
    bigReal result;

    // Perform subtraction and store the result in the bigReal object
    result.number = subtraction(num1, num2);

    // Check conditions to determine the sign of the result
    bool ok = false, is_determined = false;
    if (num1 < num2) {
        swap(num1, num2);
        swap(sign1, sign2);
        ok = true;
    }

    if (sign1 == sign2) {
        res = subtraction(num1, num2);

        if (sign1 == '-')
            ok = !ok;
    } else {
        res = addition(num1, num2);
        if (sign == '-') {
            result.sign = '-';
            is_determined = true;
        } else {
            result.sign = '+';
            is_determined = true;
        }
    }

    // Remove leading zeros from the result
    bool right = false;
    for (long long i = 0; i < res.length(); i++) {
        if (res[i] != '-' && res[i] != '0') {
            right = true;
        }
        if (!right && res[i] == '0') {
            res.erase(i, 1);
            i--;
        }
    }

    // If the result is empty, set it to "0"
    if (res.empty())
        res = "0";

    // Determine the sign based on the conditions
    if (!is_determined && (ok)) {
        result.sign = '-';
    } else if (!is_determined) {
        result.sign = '+';
    }

    // Set the final result to the bigReal object and return it
    result.number = res;
    return result;
}

// Comparison operators
// Overloaded greater than operator for bigReal class
bool bigReal::operator>(bigReal n2) {
    // Check if signs are different
    if (this->sign != n2.sign) {
        // If the current number is positive and the other is negative, current number is greater
        if (this->sign == '+') {
            return true;
        } else {
            return false;
        }
    } else if (this->sign == '+') {
        // If both numbers are positive, compare their integral and fractional parts
        if (this->allNumber > n2.allNumber) {
            return true;
        } else if (this->allNumber < n2.allNumber) {
            return false;
        } else if (this->allNumber == n2.allNumber) {
            return this->fraction > n2.fraction;
        }
    } else if (this->sign == '-') {
        // If both numbers are negative, compare their integral and fractional parts
        if (this->allNumber < n2.allNumber) {
            return true;
        } else if (this->allNumber > n2.allNumber) {
            return false;
        } else if (this->allNumber == n2.allNumber) {
            return this->fraction < n2.fraction;
        }
    }
}
// Overloaded less than operator for bigReal class
bool bigReal::operator<(bigReal n2) {
    // Check if signs are different
    if (this->sign != n2.sign) {
        // If the current number is negative and the other is positive, current number is smaller
        if (this->sign == '-') {
            return true;
        } else {
            return false;
        }
    } else if (this->sign == '+') {
        // If both numbers are positive, compare their integral and fractional parts
        if (this->allNumber < n2.allNumber) {
            return true;
        } else if (this->allNumber > n2.allNumber) {
            return false;
        } else if (this->allNumber == n2.allNumber) {
            return this->fraction < n2.fraction;
        }
    } else if (this->sign == '-') {
        // If both numbers are negative, compare their integral and fractional parts
        if (this->allNumber > n2.allNumber) {
            return true;
        } else if (this->allNumber < n2.allNumber) {
            return false;
        } else if (this->allNumber == n2.allNumber) {
            return this->fraction > n2.fraction;
        }
    }
}
// Overloaded equal to operator for bigReal class
bool bigReal::operator==(bigReal n2) {
    // Check if signs and number parts are equal
    return (this->sign == n2.sign && this->allNumber == n2.allNumber && this->fraction == n2.fraction);
}