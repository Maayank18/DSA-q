// This will be an extension to the basic of trie 
//  here we will unsert the following operation to be performed
// INSERT, COUNT THE WORDS, COUNT THE WORDS THAT END WITH , ERASE A WORD

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

struct Node{
    Node * links[26] = {NULL};
    int cntendWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    void put( char ch, Node * node){
        links[ch-'a'] = node;
    }

    Node * get(char ch){
        return links[ch-'a'];
    }

    void increaseEndWith(){
        cntendWith++;
    }

    void increasePrefix(){
        cntPrefix++;
    }

    void deleteEnd(){
        cntendWith--;
    }

    void reducePrefix(){
        cntPrefix--;
    }

    int getEnd(){
        return cntendWith;
    }

    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
    private:
    Node * root = new Node();

    public:
    Trie(){
        Node * node = root;
    }

    void insert(string word){
        Node * node = root;
        for( int i = 0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node);
            }

            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo( string word){
        Node * node = root;
        for( int i = 0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getEnd();
    }


    int countWordsStartingWth( string word){
        Node * node = root;
        for( int i = 0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->getPrefix();
    }


    void Erase( string word){
        Node * node =root;
        for( int i = 0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else{
                return;
            }
        }
        node->deleteEnd();    
    }
};


int main() {
    Trie trie;

    // Inserting words
    trie.insert("apple");
    trie.insert("apple");
    trie.insert("app");
    trie.insert("ape");

    // Counting words equal to
    cout << "Count of word 'apple': " << trie.countWordsEqualTo("apple") << endl; // 2
    cout << "Count of word 'app': " << trie.countWordsEqualTo("app") << endl;     // 1

    // Counting words starting with prefix
    cout << "Count of words starting with 'ap': " << trie.countWordsStartingWth("ap") << endl; // 4
    cout << "Count of words starting with 'app': " << trie.countWordsStartingWth("app") << endl; // 3

    // Erasing a word
    trie.Erase("apple");
    cout << "Count of word 'apple' after one erase: " << trie.countWordsEqualTo("apple") << endl; // 1
    cout << "Count of words starting with 'app' after erase: " << trie.countWordsStartingWth("app") << endl; // 2

    trie.Erase("apple");
    cout << "Count of word 'apple' after second erase: " << trie.countWordsEqualTo("apple") << endl; // 0

    trie.Erase("app");
    cout << "Count of word 'app' after erase: " << trie.countWordsEqualTo("app") << endl; // 0

    // Erasing a non-existent word (no effect)
    trie.Erase("banana");

    return 0;
}