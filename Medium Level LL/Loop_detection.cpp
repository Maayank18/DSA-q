#include<iostream>
#include<map>
using namespace std;

struct node{
    int data;
    node * next;
};

void traversal(node * head){
    node * temp = head;
    while( temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

// BRUTE FORCE SOLUTION INVOLVING A EXTERNAL DATA TYPE THAT IS A MAP AND 
// TIME COMPLEXITY WILL BE LOG WHICH WE HAVE TO REWATCH AND UNDERSTAND 

bool findLoop( node * head){     
    map<node*,int> mpp;
    node * temp = head;
    while( temp != NULL){
        if( mpp.find(temp) != mpp.end()){
            return true;
        }else{
            mpp[temp] = 1;
            temp = temp -> next;
        }
    }
    return false;
}


// OPTIMAL SOLUTION WILL BE INVOLVING HARE AND TORTOISE ALGORITHM 

bool findLoop( node * head){
    node * slow = head;
    node * fast = head;

    while( fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if( fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;

    // Initialize data and next pointers for each node
    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = nullptr; // Last node points to nullptr

    traversal(head);
    cout<<endl;
    cout<<" is the loop present : "<<findLoop(head)<<endl;

    return 0;
}