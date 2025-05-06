// This particular problem aims to reverse the linked list in groups 
// not the entire linked list but the groups


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

// Function to reverse a singly linked list
node* reverse(node* head) {
    node* temp = head;
    node* prev = NULL;

    while (temp != NULL) {
        node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Function to find the k-th node starting from 'head'
node* findKth(node* head, int k) {
    node* temp = head;
    int i = 1;
    while (i<k && temp != NULL) {
        temp = temp->next;
        i++;
    }
    return temp;
}

// Function to reverse a linked list in groups of k
node* Reverse_In_Groups(node* head, int k) {
    node * temp = head;
    node * prevNode = NULL;

    while( temp != NULL) {
        node * KNode = findKth(temp,k);

        if( KNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }

        node * nextNode = KNode->next;
        KNode->next = NULL;
        node* NewHead = reverse(temp);

        if(temp == head){
            head = KNode;
        }else{
            prevNode -> next = KNode;
        }

        prevNode = temp;
        temp = nextNode;

    }
    return head;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
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
    head = Reverse_In_Groups(head, 2);

    // Print the modified list
    cout << "Reversed in groups of 2: ";
    traverse(head);

    return 0;
}
