// in this we gonna understand how to implement the TRIE DATA STRUCTURE
// it uses major method that are :- Insert, Search and StartsWith
// One important thing is it uses REFERENCES

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

struct Node{
    Node * links[26] = {NULL};
    bool flag = false;

    // does my node contains this letter ?
    bool containskey( char ch ){
        return (links[ch-'a'] != NULL);
    }

    // creating a linkage refernce for our current character
    void put(char ch, Node * node){
        links[ch-'a'] = node;
    }

    Node * get(char ch){
        return links[ch-'a'];
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
    Node * root;


    public:
    Trie(){  // Initializing our trie data structure here 
        root = new Node();
    }

    // Time complexity for inserting is Length of the word
    void insert( string word){  // Implementation of a insert function
       Node * node = root;
       for(int i = 0; i<word.length(); i++){
          // check whether character i exist or NOT in order to insert 
          if(!node->containskey(word[i])){
             node->put(word[i], new Node());
          }

          //   moves to the reference trie
          node = node->get(word[i]);
       }
       // reached the end reference
       node->setEnd();  
    }

    //  TC -> O(length of word)
    bool search(string word){
        Node* node = root;
        for(int i = 0; i<word.length(); i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }

        // if end refernce is true hence the word searched succesful
       // otherwise the searched word NOT THERE
        return node->isEnd();
    }


    // TC-> O(length of word )
    bool startsWith( string word){
        Node* node = root;
        for(int i =0; i<word.length(); i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;     // 1
    cout << trie.search("app") << endl;       // 0
    cout << trie.startsWith("app") << endl;   // 1
    trie.insert("app");
    cout << trie.search("app") << endl;       // 1
}

