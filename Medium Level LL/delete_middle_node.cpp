// This problme aims to find the middle node and delete it 
// in case of odd numbers we have only 1 middle 
// in case of even numbers we have M1 and M2 so we will delete M2;

// TIME COMPLEXITY -> O(N) + O(N/2) (being the two pass solution)
// SPACE COMPLEXITY -> O(1)


#include<iostream>
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

int total_nodes( node * head){
    node * temp = head;
    int counter = 0;
    while( temp != NULL){
        temp = temp -> next;
        counter++;
    }
    return counter;
}

int len( node * head){
    node * temp = head;
    int counter = 0;
    while ( temp != NULL){
        temp = temp -> next;
        counter++;
    }
    return counter;
}

node * Delete_middle( node * head){
    int count = len(head)/2;
    node * temp = head;

    int i =1;
    while ( i<count){
        temp = temp -> next;
        i++;
    }
    node * delnode = temp -> next;
    temp -> next = temp -> next -> next;
    free(delnode);
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
    head = Delete_middle(head);
    traversal(head);
    return 0;
}


// Better / Optimal Solutio will again be using tortoise and hare algorithm 
// fast and slow pointer approach

// VERY IMPORTANT -> AS WE HAVE TO REACH ONE STEP BEFORE THE MIDDLE NODE WE WILL
// MAKE CHNAGES TO THE TORTOISE AND HARE ALGORITHM THAT IS 
// WE WILL SKIP A SLOW INCREMENT AND LET FAST MOVE OTSELF ONE TIME FOR FREE

// TIME COMPLEXITY -> O(N/2) (as we are mving till half only)
// SPACE COMPLEXITY -> O(1)

#include<iostream>
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

node * Delete_middle( node * head){
    node * slow = head;
    node * fast = head->next->next;

    while( fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    node * deletenode = slow -> next;
    slow -> next = slow -> next -> next;
    free(deletenode);
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
    head = Delete_middle(head);
    traversal(head);
    return 0;
}

