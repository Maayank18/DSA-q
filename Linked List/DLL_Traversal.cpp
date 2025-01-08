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
    return 0;

}