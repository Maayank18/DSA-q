#include<iostream>
using namespace std;

struct stackNode{
    int data;
    stackNode* next;

    stackNode(int d){
        data = d;
        next = NULL;
    }
};

