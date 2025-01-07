// this problem aims to give a solution for counting how many times a particular element
// is available in the array whether an integer or string 

// BRUTE FORCE SOLUTION -> this include trvaersal in the array using a for loop 
// FOR NUMBERS / INTEGRS 

// #include<iostream> 
// using namespace std;

// int counting( int arr[], int n, int target){
//     int count = 0;
//     for(int i = 0; i<n ;i++){
//         if( arr[i] == target ){
//             count++;
//         }
//     }
//     return count;
// }

// int main(){
//     int n;
//     cout<<" enter the size of array : ";
//     cin>>n;

//     int arr[n];

//     cout<<" enter the elements in array : ";
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }

//     int target;
//     cout<<" enter the elements whose target you wanna find : ";
//     cin>>target;

//     int count_frequnecy = counting(arr,n,target);

//     cout<<" the frequency of "<<target<<" in array is "<<count_frequnecy<<endl;

//     return 0;
// }


// BRUTE FORCE SOLUTION -> this include trvaersal in the array using a for loop 
// FOR STRINGS / ALPHABETS

// #include <iostream>
// #include <string>
// using namespace std;

// int counting(string str, char target) {
//     int count = 0;
//     for( int i = 0; i<str.length(); i++){
//         if(str[i] == target){
//             count++;
//         }
//     }
//     return count;
// }

// int main() {
//     string str;
//     cout << "Enter a string: ";
//     getline(cin, str); // To read the entire line, including spaces.

//     char target;
//     cout << "Enter the character you want to count: ";
//     cin >> target;

//     int count_frequency = counting(str, target);

//     cout << "The frequency of '" << target << "' in the string is " << count_frequency << endl;

//     return 0;
// }


//  better solution incloves using the hashing approach which reqires a pre computation
// WORKS FINE FOR NUMBERS 

// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     cout<<" enter the size of array : ";
//     cin>>n;

//     int arr[n];

//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }
//     // pre computation
//     int hash[20] = {0};
//     for( int i = 0; i<n; i++){
//         hash[arr[i]]++;
//     }

//     int queries;
//     cin>>queries;

//     while(queries--){
//         int number;
//         cin>>number;
//         cout<<" the number "<< number <<" is present "<<hash[number]<<" times"<<endl;
//     }
//     return 0;
// }


// better solution for counting the frequencies of letters using hashing
// somewhat a similar approach but includes a concept of ASCII VALUE

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin>>s;

    // pre computation
    int hash[256] = {0};
    for( int i = 0; i<s.length(); i++){
        hash[s[i]]++;
    }

    int queries;
    cin>>queries;

    while(queries--){
        char ch;
        cin>>ch;
        cout<<hash[ch]<<endl;
    }
    return 0;
}