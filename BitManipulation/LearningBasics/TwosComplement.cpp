// add 1 to the ones complement that is found will be our 2's complement

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// Step 1: Get 1's complement
void onesComplement(string &ans) {
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = (ans[i] == '1') ? '0' : '1';
    }
}

// Step 2: Add 1 to the 1's complement
string addOneToBinary(string bin) {
    int carry = 1;  // Start with 1 (for adding)
    int n = bin.size();

    for (int i = n - 1; i >= 0; i--) {
        if (bin[i] == '1' && carry == 1) {
            bin[i] = '0';
            carry = 1;
        } else if (bin[i] == '0' && carry == 1) {
            bin[i] = '1';
            carry = 0;
        }
    }

    if (carry == 1) {
        bin = '1' + bin;
    }

    return bin;
}

// Main conversion function
string twosComplement(int decimal) {
    string ans = "";

    // Decimal to binary
    while (decimal > 0) {
        ans += (decimal % 2 == 1) ? '1' : '0';
        decimal /= 2;
    }

    reverse(ans.begin(), ans.end());

    // Pad with leading zeros to make it 8-bit (optional)
    while (ans.length() < 8) {
        ans = '0' + ans;
    }

    // Step 1: One's complement
    onesComplement(ans);

    // Step 2: Add 1
    string result = addOneToBinary(ans);

    return result;
}

int main() {
    int decimal = 23;
    string twosComp = twosComplement(decimal);
    cout << "2's complement of " << decimal << " is: " << twosComp << endl;
    return 0;
}
