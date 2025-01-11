// this problem basically aims to give the count of number of elements present in 
// loop or cycle if one exist otherwise the count is 0


//BRUTE FORCE -> extremely basic way in whicc we will use hashing to keep a counter/timer
// and find the elements present 


#include<iostream>
#include<map>
using namespace std;

struct node{
    int data;
    node * next;
};


int count_Ele_Loop( node * head){
    map<node*,int> mpp;
    node * temp = head;
    int timer = 1;

    while( temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return (timer - value);
        }else{
            mpp[temp] = timer;
            timer++;
            temp = temp -> next;
        }
    }
    return 0;
}



int main(){
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;
    node* fifth = new node;


    // Initialize data and next pointers for each node
    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth; 

    fourth->data = 50;
    fourth->next = fifth;

    fifth->data = 60;
    fifth->next = third;

    cout<<endl;

    cout<<" the starting point in loop in LL is "<<count_Ele_Loop(head)<<endl;

    return 0;
}


// Again the optimised solution will be using tortoise and hare algorithm

#include<iostream>
#include<map>
using namespace std;

struct node{
    int data;
    node * next;
};

int findLen( node * slow, node * fast){
    int count = 1;
    slow = slow -> next;
    while( slow != fast){
        slow = slow -> next;
        count++;
    }
    return count;
}


int count_Ele_Loop( node * head){
    node * slow = head;
    node * fast = head;

    while( fast!=NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if( fast == slow){
            return findLen(slow,fast);
        }
    }
    return 0;
}



int main(){
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;
    node* fifth = new node;


    // Initialize data and next pointers for each node
    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth; 

    fourth->data = 50;
    fourth->next = fifth;

    fifth->data = 60;
    fifth->next = third;

    cout<<endl;

    cout<<" the starting point in loop in LL is "<<count_Ele_Loop(head)<<endl;

    return 0;
}