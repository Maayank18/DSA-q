#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void traversal (node*head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}

// node* InserAtTail(node*head,int data){  // INSERT AT BEGINNING
//     node* newNode = new node;
//     newNode -> data = data;
//     newNode -> next = head;
//     return newNode;
// }


// node * InsertAtTail( node* head, int data){    //INSERT AT TAIL
//     node * ptr = head;
//     node * newNode = new node;
//     while(ptr -> next != NULL){
//         ptr = ptr -> next;
//     }
//     newNode -> data = data;
//     ptr -> next = newNode;
//     newNode -> next = NULL;
//     return head;
// }


node* InsertAtIndex( node* head, int data, int index){
    node * p = head;
    node * newNode = new node;
 
    int i = 0;
    while( i<index-1){
        p = p-> next;
        i++;
    }
    newNode -> data = data;
    newNode->next = p->next;
    p->next = newNode;

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
    // head = InserAtTail(head,70);
    // head = InsertAtTail(head,70);
    head = InsertAtIndex(head,70,2);
    traversal(head);
    cout<<endl;

    return 0;
}
    