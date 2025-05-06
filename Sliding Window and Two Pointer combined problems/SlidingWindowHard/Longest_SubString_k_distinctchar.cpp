



// BRUTE FORCE SOLUTION 
// TIME COMPLEXITY -> O(N^2) X log(256) because of map and using all char case
// SPACE COMPLEXITY -> O(256) storing all characters
// #include<iostream>
// #include<string>
// #include<map>
// using namespace std;

// int longestSubArrayWithKdistinct(string s, int k){
//     int n = s.size();
//     map<char,int> mpp;
//     int maxLen = 0;

//     for(int i = 0; i<n; i++){
//         mpp.clear();
//         for(int j = i; j<n; j++){
//             mpp[s[j]]++;
//             if(mpp.size()<=k){
//                 maxLen = max(maxLen,j-i+1);
//             }else{
//                 break;
//             }
//         }
//     }
//     return maxLen;
// }

// int main(){
//     string s = "aaabbccdd";
//     int lengthMax = longestSubArrayWithKdistinct(s,2);
//     cout<<" max length of such subarray is : "<<lengthMax<<endl;
//     return 0;
// }


// BETTER SOLUTION
// TIME COMPLEXITY -> O(N) + O(N) + O(256) = 2 while loops + hashmaps
// SPACE COMPLEXITY -> O(256)
// #include<iostream>
// #include<string>
// #include<map>
// using namespace std;

// int longestSubArrayWithKdistinct(string s, int k){
//     int n = s.size();
//     map<char,int>mpp;
//     int l = 0;
//     int r = 0;
//     int maxLen = 0;

//     while(r<n){
//         mpp[s[r]]++;

//         while(mpp.size()>k){
//             mpp[s[l]]--;
//             if(mpp[s[l]] == 0) mpp.erase(s[l]);
//             l++;
//         }

//         if(mpp.size()<=k){
//             maxLen = max(maxLen,r-l+1);
//         }
//         r++;
//     }
//     return maxLen;
// }

// int main(){
//     string s = "aaabbccdd";
//     int lengthMax = longestSubArrayWithKdistinct(s,2);
//     cout<<" max length of such subarray is : "<<lengthMax<<endl;
//     return 0;
// }

// OPTIMAL SOLUTION
// TIME COMPLEXITY -> O(N)
// SPACE COMPLEXITY -> O(256)
#include<iostream>
#include<string>
#include<map>
using namespace std;

int longestSubArrayWithKdistinct(string s, int k){
    int n = s.size();
    map<char,int>mpp;
    int l = 0;
    int r = 0;
    int maxLen = 0;

    while(r<n){
        mpp[s[r]]++;

        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }

        if(mpp.size()<=k){
            maxLen = max(maxLen,r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){
    string s = "aaabbccdd";
    int lengthMax = longestSubArrayWithKdistinct(s,2);
    cout<<" max length of such subarray is : "<<lengthMax<<endl;
    return 0;
}

