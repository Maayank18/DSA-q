// our task is to convert roman to integer and vice versa 

// BRUTE FORCE APPRAOCH 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to convert an integer to a Roman numeral
string intToRoman(int num) {
    // Define the integer values in descending order
    vector<int> values = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    // Corresponding Roman numeral symbols for the values
    vector<string> symbols = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    // Initialize result string to store the Roman numeral
    string roman = "";

    // Loop through each value starting from the largest
    for (int i = 0; i < values.size(); i++) {
        // While the current value can be subtracted from num
        while (num >= values[i]) {
            roman += symbols[i];  // Append the Roman symbol
            num -= values[i];     // Subtract the value from num
        }
    }

    // Return the final Roman numeral string
    return roman;
}

int main() {
    int number;

    // Ask the user for an input number
    cout << "Enter an integer (1 to 3999): ";
    cin >> number;

    // Convert the number to Roman numeral and print it
    cout << "Roman numeral: " << intToRoman(number) << endl;

    return 0;
}





// converting the roman number to value 

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to convert Roman numeral to integer
int romanToInt(const string& s) {
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5},   {'X', 10},
        {'L', 50}, {'C', 100},{'D', 500}, {'M', 1000}
    };

    int result = 0;

    for (int i = 0; i < s.size(); i++) {
        // Get value of current and next symbols
        int current = romanMap[s[i]];
        int next = (i + 1 < s.size()) ? romanMap[s[i + 1]] : 0;

        if (current < next) {
            result -= current; // Subtractive case
        } else {
            result += current; // Normal addition
        }
    }

    return result;
}

int main() {
    string roman;
    cout << "Enter Roman numeral: ";
    cin >> roman;

    cout << "Integer value: " << romanToInt(roman) << endl;
    return 0;
}

