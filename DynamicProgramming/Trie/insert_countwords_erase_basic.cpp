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

    void increaseEnd(){
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
        node->increaseEnd();
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