// eg we have str = "abab"
// all the substrings for this will be : {"a","ab","aba","abab","b","ba","bab",""}
// hence there are total of 8 including the empty sub string

// Two methods for solving this is 
// 1. using a set data structure 
// 2. Using the Trie


// Method one solving
// Time complexity = n^2 for the for loops * log m ( m = length os string for the set )
// Space complexity = considering in the worst case all the substring generated are different 
// and each takes on an average of O(n/2 space) = total = n^2 x n/2 = around n^3 whihc is not that good
// #include<iostream>
// #include<string>
// #include<set>
// #include<bits/stdc++.h>
// using namespace std;

// int f(string str){
//     int s = str.size();
//     set<string> st;
//     string temp = ""; // after doing this step and below step we coorectly add +1 
//     st.insert(temp);  // for considering the mepty string too so answer is coming 8
//     for(int i = 0; i<s; i++){
//         temp = "";
//         for(int j = i; j<s; j++){
//             temp+=str[j];
//             st.insert(temp);
//         }
//     }

//     return st.size();
// }

// int main(){
//     string str = "abab";
//     int DistinctSubstring = f(str);
//     cout<<" total distinct substring are : "<<DistinctSubstring<<endl;
//     return 0;
// }



// METHOD TWO OF SOLVING using TRIE

#include<iostream>
#include<string>
#include<set>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node * links[26] = {NULL};

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node * node){
        links[ch-'a'] = node;
    }

    Node * get(char ch){
        return links[ch-'a'];
    }

    
};

class Trie{
    private:
    Node* root = new Node();

    public:

    Trie(){
    }

    int DistinctSubstring(string word){
        int count = 0;
        for(int i = 0; i<word.size(); i++){
            Node * node = root;
            for(int j = i; j<word.size(); j++){
                if(!node->containsKey(word[j])){
                    count++;
                    node->put(word[j],new Node());
                }
                node = node->get(word[j]);
            }
        }
        return count+1;
    }
};


int main() {
    Trie trie;
    string s = "abab";

    int result = trie.DistinctSubstring(s);
    cout << "Number of distinct substrings: " << result << endl;

    return 0;
}