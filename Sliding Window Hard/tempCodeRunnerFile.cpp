#include<iostream>
// #include<string>
// #include<map>
// #include<bits/stdc++.h>
// using namespace std;

// string minimum_Length_Window(string s, string t){
//     int n = s.size();
//     int m = t.size();
//     int minLen = INT_MAX;
//     int sIndex = -1;

//     for(int i = 0;i<n; i++){
//         int hash[256] = {0};
//         int count = 0;
//         for(int j = 0; j<m; j++ ){
//             hash[t[j]]++;
//         }

//         for( int j = i; j<n; j++){
//             if(hash[s[j]]>0){
//                 count++;
//                 hash[s[j]]--;
//             }

//             if(count == m){
//                 minLen = min(j-i+1,minLen);
//                 sIndex = i;
//                 break;
//             }
//         }
//     }
//     return s.substr(sIndex,minLen);
// }

// int main(){
//     string s = "ddaaabbca";
//     string t = "abc";
//     string answer = minimum_Length_Window(s,t);
//     cout<<" the required minimal string is : "<<answer<<endl;
//     return 0;
// }