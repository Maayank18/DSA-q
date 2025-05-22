// This problem basically tends to ask us to return the longest word 
//  who has all the prefixes in the nodes
// complete strings means that each adn every character must be present 

// BASIC LOGIC HERE IS THAT ALL THE NODES( MARKING THEM TO
//  BE PRESENT ) SHOULD HAVE A FLAG TRUE 

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node * links[26] = {NULL};
    bool flag = false;

    bool containsKey( char ch){
        return (links[ch-'a']!=NULL);
    }

    void put(char ch, Node * node){
         links[ch-'a'] = node;
    }

    Node * get(char ch){
        links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private: 
    Node * root = new Node();

    public:

    Trie(){
        Node * node = root;
    }

    void insert( string word){
        Node * node = root;

        for(int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool checkIfPrefixExist( string word){
        bool flag = true;
        Node * node = root;

        for(int i = 0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd() == false) return false; // if my final value is false
            }

            return false;
        }
        return true;
    }

    
};


string LongestWord(int n, vector<string> &word){
    Trie trie;

    // after this loop all my words would be inserted
    for( auto it : word){
        trie.insert(it);
    }


    string longestString = "";

    for(auto it : word){
        if(trie.checkIfPrefixExist(it)){
            if(it.length() > longestString.length()){
                longestString = it;
            }else if (it.length() == longestString.length() ||
                     it.length() < longestString.length()){ // maintaing the lexicographical order

                longestString = it;
            }
        }
    }

    if( longestString == "") return NULL;
    return longestString;
}

int main() {
    vector<string> words = {"a", "app", "ap", "appl", "apple", "apply"};
    int n = words.size();

    cout << "Longest Word with all prefixes present: " << LongestWord(n, words) << endl;

    return 0;
}
