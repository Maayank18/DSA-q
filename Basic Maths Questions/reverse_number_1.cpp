#include <iostream>
using namespace std;

int reverse(int n) {
    int reversednum = 0; // Initialize reversednum to 0
    while (n > 0) {
        int lastdigit = n % 10; // Get the last digit
        reversednum = (reversednum * 10) + lastdigit; // Update the reversed number
        n = n / 10; // Remove the last digit from n
    }
    return reversednum;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = reverse(n);
    cout << "Reversed number: " << result << endl;
    return 0;
}
