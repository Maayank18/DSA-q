// our aims is to sort the given string in order of decreasing frequency 
// eg s = "tree"  e = 2, t = 1, r = 1
// output = eert | eetr

#include<iostream>
#include<string>
#include<map>
#include<bits/stdc++.h>
using namespace std;

// Comparator function
bool comparePairs(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}

string find(string s) {
    // Step 1: Frequency map
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Transfer map to vector of pairs
    vector<pair<char, int>> vec;
    for (auto& entry : freq) {
        vec.push_back(entry);
    }

    // Step 3: Sort using comparator function
    sort(vec.begin(), vec.end(), comparePairs);

    // Step 4: Construct output string
    string result = "";
    for (auto& p : vec) {
        result += string(p.second, p.first);
    }

    return result;
}

int main(){
    string s = "tree";
    string decFrequencyOrder = find(s);
    cout<<" the string is decreasing order of frequency is : "<<decFrequencyOrder<<endl;
    return 0;
}