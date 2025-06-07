// the basic aim of this problem is :
// for all substring find the difference of maxfreqchar - minfrqchar 
// and sum that all will be our answer


#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int count(string &s){
    int n = s.length();
    int ansbeauty = 0;
    for(int i = 0; i<n; i++){
        vector<int> frequ(26,0);
        for(int j = i; j<n; j++){
            frequ[s[j]-'a']++;
            int maxFreq = 0, minFreq = INT_MAX; 
            for(int freq : frequ){
                if(freq > 0){
                    maxFreq = max(maxFreq,freq);
                    minFreq = min(minFreq,freq);
                }
            }

            ansbeauty += (maxFreq-minFreq);
        }
    }
    return ansbeauty;
}

int main(){
    string s = "aabca";
    int beauty = count(s);
    cout<<" the beautiful number is : "<<beauty<<endl;
    return 0;
}