// ALWAYS REMEMBER IF THERE IS SOMETHING WHEN ANSWER IS CONTINOUSLY VALID TILL SOME POINT 
// AND AFTER THAT IT IS NOT CONTINUOUSLY VALID THEN IT WOULD BE USING 
// BINARY SEARCH

// this is basic case case in which we are playing with numbers just under stand
// basic logic

//brute force approach
// #include<iostream>
// using namespace std;

// int squareroot( int t){
//     if( t == 0 ) return 0;

//     for(int i = t; i<=t; i--){
//         if( i*i <= t){
//             return i;
//             // this is one way another we can use continue here and else 
//             // we can break
//         }
//     }

// }

// int main(){
//     int t;
//     cout<<" enter number whose square root that need to be found : "<<endl;
//     cin>>t;

//     int result = squareroot(t);

//     cout<<" the square root of "<<t<<" is :"<<result;
//     return 0;
// }


// binary search approach

#include<iostream>
using namespace std;

int squareroot( int t){
    if ( t == 0) return 0;

    int low = 1;
    int high = t;
    int answer = 1;
    
    while( low<=high){
        int mid = low + (high-low)/2;

        if(mid*mid <= t){
            answer = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return answer;
}

int main(){
    int t;
    cout<<" enter number whose square root that need to be found : "<<endl;
    cin>>t;

    int result = squareroot(t);

    cout<<" the square root of "<<t<<" is :"<<result;
    return 0;
}