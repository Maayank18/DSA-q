// basic linear search approach in which we usually 
// take two loops and one goes from till n and other approx
// n so TC is O(n^2) and space complexity is O(1)

#include<iostream>
using namespace std;

int missing( int arr[], int n){
    int flag;
    for(int i = 1; i<=n; i++){
         flag = 0;
        for( int j = 0; j<n; j++){
            if(arr[j]==i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return -1;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" The arrays entered by the user : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int result = missing(arr,n);
    cout<<" is the number missing :"<<result;
    return 0;
}

// better solution includes hashing in which we start
// with basically keeping all elements 0 and as soon as
// we start iterating in array we mark element with 1 
// and again iterating whichever eleemnt has a hash value 
// 0 is our missing number TC is about O(n) and 
// space complexity is about O(n)

#include<iostream>
using namespace std;

int missing_hash(int arr[], int n){
    int hash[n+1] = {0};

    for(int i = 0; i<n; i++){
        if (arr[i] <= n && arr[i] > 0){
            hash[arr[i]] = 1;
        }
    }

    for(int i = 1; i<=n; i++){
        if(hash[i] == 0){
             return i; // missing number is hash[arr[i]];
        }
    }
    return -1; // no missing number 
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" The arrays entered by the user : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int result = missing_hash(arr,n);
    if (result == -1) {
        cout << "No number is missing." << endl;
    } else {
        cout << "The missing number is: " << result << endl;
    }
    return 0;
}


//Now talking about the optimal solution there will be
//two optimal solution ONE IS SUM and ONE IS XOR
// SUM includes finding sum of first n natural number
//subtracting the sum of all numbers present in array and 
//by this we get our missing terms

//XOR code to be viewed - basic xor concept used 



#include<iostream>
using namespace std;

int missing_opt( int arr[], int n){
    int sum_of_n = (n*(n+1))/2;

    int sum = 0;
    for(int i = 0; i<n-1; i++){
        sum = sum + arr[i];
    }

    return sum_of_n - sum;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for( int i = 0; i<n-1; i++){
        cin>>arr[i];
    }

    cout<<" The arrays entered by the user : ";
    for( int i = 0; i<n-1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int result = missing_opt(arr,n);
    cout << "The missing number is: " << result << endl;
    return 0;
}