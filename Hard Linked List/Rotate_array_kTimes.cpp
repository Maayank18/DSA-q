// This particular problem aims to rotate the linked list k times


#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// Function to traverse and print the linked list
void traverse(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int count( node * head){
    node * temp = head;
    int counting = 0;
    while( temp != NULL){
        counting++;
        temp = temp -> next;
    }
    return counting;
}

node* rotating_array(node* head, int k) {
    node * tail = head;
    node * temp = head;

    int len = count(head);
    int i = 1;
    while( i<len && tail->next != NULL){
        i++;
        tail = tail->next;
    }
    tail -> next = head;

    k = k%len;
    if(k == 0) return head;

    int difference = len-k;
    int j = 1;
    while(j<difference && temp!=NULL){
        temp = temp -> next;
        j++;
    }
    head = temp -> next;
    temp -> next = NULL;

    return head;
}



int main() {
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = NULL;

    // Print the original list
    cout << "Original list: ";
    traverse(head);

    // Reverse the list in groups of 2
    head = rotating_array(head, 2);

    // Print the modified list
    cout << "Reversed in groups of 2: ";
    traverse(head);

    return 0;
}
