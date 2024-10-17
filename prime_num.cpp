#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

  

    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) { // If divisors are not equal, count the pair
                cnt++;
            }
        }
    }

    if (cnt == 2) {
        cout << "Yes, it is prime.";
    } 
    return 0;
}
