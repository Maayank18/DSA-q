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

node * deleteAtBegin( node * head){     //DELETION AT BEGINNING 
    node* ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

node * deleteAtTail(node * head){         // DELETION AT TAIL

    // Handle the case where the list is empty
    if (head == nullptr) {
        return nullptr;
    }

    // Handle the case where the list has only one node
    if (head->next == nullptr) {
        delete head; // Free the memory of the single node
        return nullptr; // Return nullptr as the new head
    }
    node * ptr = head;
    while( ptr->next->next != NULL){
        ptr = ptr->next;
    }
    delete ptr->next;
    ptr -> next = NULL;
    return head;
}

node * deleteAtIndex ( node * head, int index){
    node * p = head;
    node * q = head -> next;

    for( int i = 0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete q;
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
    third->next = NULL; // Last node points to nullptr

    traversal(head);
    cout<<endl;
    // head = deleteAtBegin(head);
    // head = deleteAtTail(head);
    head = deleteAtIndex(head,2);
    traversal(head);
    cout<<endl;

    return 0;
}