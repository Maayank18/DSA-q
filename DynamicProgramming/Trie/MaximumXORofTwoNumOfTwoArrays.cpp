// this question aims to find the maximum xor value of two elemts 
// of two different arrays 
// eg. we have array1 size n and array2 size m
// we selekcted a from 1 and b from 2 
// we need to fins two such elements that the xor is max 
// given that the two elements shoudl be from diffrent arrays only

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node * links[2] = {NULL};

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    Node * get(int bit){
        return links[bit];
    }

    void put(int bit, Node * node){
        links[bit] = node;
    }

};

class Trie{
    private:
    Node * root = new Node();

    public:
    Trie(){
        Node * node =  root;
    }

    void insert( int num){
        Node * node = root;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;  // setting of the bit
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node * node = root;
        int maxNum = 0;
        for( int i = 31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }

};


int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2 ){
    Trie trie;
    for( auto it : arr1){
        trie.insert(it);
    }
    int maxi = 0;
    for(auto it : arr2){
        maxi = max(maxi,trie.getMax(it));
    }

    return maxi;
}


int main() {
    // Static input arrays
    vector<int> arr1 = {1, 2, 3}; // Array 1
    vector<int> arr2 = {4, 5, 6}; // Array 2

    int n = arr1.size();
    int m = arr2.size();

    int result = maxXOR(n, m, arr1, arr2);
    cout << "Maximum XOR of elements from different arrays: " << result << endl;

    return 0;
}