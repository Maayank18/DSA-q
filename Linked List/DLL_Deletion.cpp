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

// node * DeleteAtHead( node* head){    // DELETE HEAD NODE FROM DLL
//     node * temp = head;
//     head = head->next;
//     head->prev = NULL;
//     delete temp;
//     return head;
// }


// node * DeleteAtTail( node * head){  // DELETE THE TAIL NODE
//     node * temp = head;
//     while( temp -> next->next !=NULL){
//         temp = temp ->next;
//     }
//     delete temp->next;
//     temp->next = NULL;
//     return head;
// }


// node * DeleteAtIndex( node * head, int index){ // DELETE AT INDEX
//     node* p = head;
//     node * q = head -> next;
//     int i = 0;
//     while(i<index-1){
//         p = p->next;
//         q = q->next;
//         i++;
//     }
//     p -> next = q -> next;
//     q ->next->prev = q-> prev;
//     delete q;
//     return head;
// }

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
    // head = DeleteAtHead(head);
    // head = DeleteAtTail(head);
    // head = DeleteAtIndex(head,2);
    traverse(head);
    return 0;

}