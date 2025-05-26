// OUR AIM IS TO FIND THE FINAL STRING AFTER REMOVAL OF ALL OCCURENCES OF A PARTICULAR SUBSTRING
// eg s = "dabcaaabc" and part = "abc"
// return answer daa as all occurneces of abc are removed 



// BRUTE FORCE APPROACH
// TC -> almost O(n^2) -> for finding + erasing 
// SC -> O(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void removeAllOccurences(string &s, string &part){

    // base case 
    if(part.length() > s.length()){
        return;
    }

    int index = s.find(part); // starting index of first occurences of the part

    while(index >= 0){
        s.erase(index, part.length());
        index = s.find(part);
    }
}

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    removeAllOccurences(s,part);
    cout<<" the string after removing all its occurencs is : "<<s<<endl;
    return 0;
}




// optimal approach 
// tc -> o(nxm)
// sc -> o(n)
string removeOccurrences(string s, string part) {
    string result = "";
    int partLen = part.length();

    for (char c : s) {
        result.push_back(c);

        if (result.size() >= partLen && result.substr(result.size() - partLen, partLen) == part) {
            result.erase(result.size() - partLen, partLen);
        }
    }
    return result;
}
