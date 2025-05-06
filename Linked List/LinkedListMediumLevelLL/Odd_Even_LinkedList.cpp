// this problem basically aims to gets all the odd indexes together and then all even
// index term together

// eg. if we have 1 -> 5 -> 6 -> 2 -> 3 -> 4
// answer =>  1 -> 6 -> 3 -> 5 -> 2 -> 4 ( considering 1 based indexing )


//BRUTE FORCE -> take a vector store all odd index
// then store all even index 
// then push both like wise 

// TIME COMPLEXITY -> O(N/2) + O(N/2) + O(N) = O(2N)
// SPACE COMPLEXITY -> O(N) due to vectors

#include<iostream>
#include<vector>
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

node * Odd_Even( node * head){
    vector<int> sorted_odd_even_list;
    node * temp = head;

    while(temp!= NULL && temp -> next != NULL){
        sorted_odd_even_list.push_back(temp->data);
        temp = temp -> next -> next;
    }
    if(temp) sorted_odd_even_list.push_back(temp->data);

    temp = head -> next;
    while( temp != NULL && temp -> next !=NULL){
        sorted_odd_even_list.push_back(temp->data);
        temp = temp-> next-> next;
    }
    if(temp) sorted_odd_even_list.push_back(temp->data);


    temp = head;
    int i = 0;
    while( temp != NULL){
        temp->data = sorted_odd_even_list[i];
        i++;
        temp = temp -> next;
    }
    return head;
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
    node * newest = Odd_Even(head);
    traversal(newest);

    return 0;
}


// A better solution will be better in terms of space as we wont be using any 
// external vector to store

// what we can do is keep on travelling the nodes odd and even and when we finish our odd 
// we can connect odds end with the even and rteurn the head

//TIME COMPLEXITY -> O(N)

#include<iostream>
#include<vector>
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

node * Odd_Even( node * head){
    node * odd = head;
    node * even = head -> next;
    node * evenHead = head -> next;

    while( even!= NULL && even -> next!=NULL){
        odd -> next = odd->next->next;
        even -> next = even->next->next;

        odd = odd -> next;
        even = even -> next;
    }
    odd -> next = evenHead;
    return head;
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
    node * newest = Odd_Even(head);
    traversal(newest);

    return 0;
}