#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
    node * prev;
    
};

node* traverse( node* head){
    node* temp = head;
    while( temp!=NULL){
        cout<< temp->data<<" ";
        temp = temp-> next;
    }
}

// node * InsertAtHead (node*head, int data){   // INSERTING AT HEAD
//     node * newNode = new node;
//     newNode -> data = data;
//     newNode -> next = head;
//     newNode -> prev = NULL;
//     head -> prev = newNode;
//     return newNode;
// }


// node * InsertAtTail( node * head, int data){    // INSERT AT TAIL
//     node * newNode = new node;
//     node * temp = head;
//     while( temp-> next != NULL){
//         temp = temp -> next;
//     }
//     newNode -> data = data;
//     temp -> next = newNode;
//     newNode -> next = NULL;
//     newNode -> prev = temp;
//     return head;
// }


node * InsertAtIndex( node* head, int data, int index){
    node * newNode = new node;
    node* p = head;
    node* q = head -> next;

    int i = 0;
    while( i<index-1){
        p = p->next;
        q = q->next;
        i++;
    }

    newNode -> data = data;
    newNode -> next = q;
    newNode -> prev = p;
    p -> next = newNode;
    q ->prev = newNode;
    return head;


}

int main(){
    node * head = new node;
    node * first = new node;
    node * second = new node;
    node * third = new node;

    head-> prev = NULL;
    head-> data =10;
    head-> next = first;

    first->prev = head;
    first-> data =20;
    first-> next = second;

    second->prev = first;
    second-> data =30;
    second-> next = third;

    third->prev = second;
    third-> data =40;
    third-> next = NULL;

    traverse(head);
    cout<<endl;
    // head = InsertAtHead(head,70);
    // head = InsertAtTail(head,70);
    head = InsertAtIndex(head,70,2);
    traverse(head);
    return 0;

}