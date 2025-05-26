// What this question ask us is that 
// we would be giev two strings s1 and s2 
// eg s1 = "ab"   s2 = "rtajsbanjk"   aswer = true 
//  we have to tell whetehr the string coontains a permuattaion or not 
// as ab permuation can be ba but the thing is they should be continuosu
// FIND IF S2 CONTAINS A PERMUATION OF S1


// TC -> O(N) = S2.LENGTH()
// SC -> O(1) = O(26) + O(26)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool checkEqual(int count1[], int count2[]){
    for(int i = 0; i<26; i++){
        if(count1[i] != count2[i]){
            return false;
        }
    }
    return true;
}

bool check(string s1, string s2){

    int count1[26] = {0};
    // here i have marked the s1 
    for(int i = 0; i<s1.length(); i++){
        count1[s1[i] - 'a']++;
    }

    int count2[26] = {0};
    int windowLen = s1.length();
    int i = 0;

    while( i < windowLen){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if(checkEqual(count1,count2)){
        return true;
    }


    // aage chalte raho and check karte raho
    while( i < s2.length()){
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - windowLen];
        int oldIdx = oldChar - 'a';
        count2[oldIdx]--;
        
        i++;

        if(checkEqual(count1,count2)){
            return true;
        }
    }
    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool isPermutation = check(s1,s2);
    cout<<" does the permutation exist in the s2 : "<<isPermutation<<endl;
    return 0;
}

