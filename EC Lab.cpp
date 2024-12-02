// Author: Carson Schraad
// KUID: 3092015
// Date Submitted: 12/1/2024
// Lab: Extra Credit Lab
# include <iostream>
# include <iomanip> 
# include <string>

using namespace std;

double extractNumeric(const string& str){
    // Find length of input
    int length = str.length();

    // Booleans for input validation
    bool decimalCheck = false;
    bool digitsCheck = false;
    bool signCheck = false;

    // If there is no string, return invalid
    if (length == 0) return -999999.99;

    // Iterate across the input
    for (int i = 0; i < length; ++i) {
        char c = str[i];

        // Check for digits
        if (c >= '0' && c <= '9') {
            digitsCheck = true;
            continue;
        }

        // Check for decimal point
        if (c == '.' && !decimalCheck) {
            decimalCheck = true;
            continue;
        }

        //Check for sign
        if ((c == '+' || c == '-') && i == 0 && !signCheck) {
            signCheck = true;
            continue;
        }

        // Return -999999.99 is anything else is found
        return -999999.99;
    }

    // If the there are no digits input is invalid
    if (!digitsCheck) return -999999.99;

    double result = 0.0;
    double decimalMultiplier = 0.1;
    bool isNegative = (str[0] == '-');
    bool isDecimal = false;

    // iterate over the input, first index is either '+' or '-', remainder are handled normally
    for (int i = (str[0] == '+' || str[0] == '-') ? 1 : 0; i < str.length(); ++i) {
        if (str[i] == '.') {
            isDecimal = true;
            continue;
        }
        // convert to int
        int digit = str[i] - '0';

        // generate int section (###)
        if (!isDecimal) {
            result = result * 10 + digit;
        } else {
            // generate decimal section (.####)
            result += digit * decimalMultiplier;
            decimalMultiplier *= 0.1;
        }
    }
    // adds negative if a sign is found
    return isNegative ? -result : result;
}

// provided main function
int main(){
    string input;

    while (true) {
        cout <<"Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }
    return 0;
}