#include<iostream>
#include<vector>
using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cin>>n; 
    cout<<"the fibonacci of "<<n<<"is"<<fibonacci(n);
    return 0;
}




// USING THE TECHNIQUE OF MEMOIZATION 

/*
----------------------------------------------
🌟 Memoization in Fibonacci Problem 🌟
----------------------------------------------

🔵 What is Memoization?
- Memoization is a technique where we store the results of already solved subproblems 
  so that we don't solve the same subproblem again and again.
- It is a type of optimization mainly used in **Dynamic Programming**.

🔵 Why use Memoization here?
- In simple recursion, the same Fibonacci numbers are calculated again and again.
- Memoization saves these calculated results in an array (dp), making it much faster.

🔵 Time Complexity (TC):
- O(n)
- Because each number from 0 to n is calculated only once.

🔵 Space Complexity (SC):
- O(n) 
- Because we use a vector 'dp' of size n+1 to store the answers.

----------------------------------------------
Now let's understand the code easily:
----------------------------------------------
*/

#include<iostream>   // For input and output
#include<vector>     // For using vector (dynamic array)
using namespace std;

// Function to calculate Fibonacci using Memoization
int fibonacci(int n, vector<int> &dp) {
    // Base case: if n is 0 or 1, return n itself
    if (n <= 1) {
        return n;
    }
    
    // If already calculated, directly return the stored value
    if (dp[n] != -1) return dp[n];
    
    // Otherwise, calculate recursively and store the result in dp[n]
    return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
}

int main() {
    int n;
    cin >> n;   // Taking input from user
    
    // Creating a dp array of size (n+1) and initializing all elements with -1
    vector<int> dp(n+1, -1);
    
    // Printing the final Fibonacci number
    cout << "The Fibonacci of " << n << " is " << fibonacci(n, dp) << endl;
    
    return 0;   // End of program
}




#include<iostream>
using namespace std;

/*
----------------------------------------------
🌟 Tabulation in Fibonacci Problem 🌟
----------------------------------------------

🔵 What is Tabulation?
- Tabulation is a technique where we **build a table (usually array or variables)** 
  from the bottom (smallest cases) up to the required answer.
- It is also called **Bottom-Up Dynamic Programming**.

🔵 Why use Tabulation here?
- It avoids recursion and stack overhead.
- It's faster and uses **O(1) space** (only a few variables are used).

🔵 Time Complexity (TC):
- O(n)
- Because we use a simple loop from 2 to n.

🔵 Space Complexity (SC):
- O(1)
- Only fixed variables are used, no extra array.

----------------------------------------------
Now let's understand the code easily:
----------------------------------------------
*/

int main() {
    int n;
    cin >> n;  // Taking input from user

    // Base cases: if n is 0 or 1, directly return n
    if (n == 0) {
        cout << "The Fibonacci of " << n << " is " << 0 << endl;
        return 0;
    }
    if (n == 1) {
        cout << "The Fibonacci of " << n << " is " << 1 << endl;
        return 0;
    }

    // prev1 = Fibonacci of (i-2)
    // prev  = Fibonacci of (i-1)
    int prev1 = 0;
    int prev = 1;

    // Loop from 2 to n to calculate Fibonacci numbers
    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev;  // Current Fibonacci = sum of last two
        prev1 = prev;             // Move prev1 and prev forward
        prev = curr;
    }

    // After the loop, 'prev' has the Fibonacci of 'n'
    cout << "The Fibonacci of " << n << " is " << prev << endl;

    return 0;  // End of program
}
