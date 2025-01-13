// This particular question aims in remove all DUPLICATES NODES arranged IN 
// SORTED MANNER
// eg, 1 -> 1 -> 1 -> 2 -> 3 -> 3 -> 4
// return 1 -> 2 -> 3 -> 4


// TIME COMPLEXITY -> one loop goes only to duplicate and another only goes to 
// non duplicates value overall TC is O(N)
// SPACE COMPLEIXTY -> O(1)

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

node * Remove_Duplicates( node * head){
    node * temp = head;

    while( temp != NULL && temp -> next !=NULL){
        node * nextNode = temp->next;
        while( nextNode != NULL && nextNode->data == temp->data){
            nextNode = nextNode -> next;
        }
        temp -> next = nextNode;
        if(nextNode) nextNode->prev = temp;
    }
    return head;
}
int main(){
    node * head = new node;
    node * first = new node;
    node * second = new node;
    node * third = new node;
    node * fourth = new node;
    node * fifth = new node;
    node * sixth = new node;

    head-> prev = NULL;
    head-> data =1;
    head-> next = first;

    first->prev = head;
    first-> data =1;
    first-> next = second;

    second->prev = first;
    second-> data =1;
    second-> next = third;

    third->prev = second;
    third-> data =2;
    third-> next = fourth;

    fourth->prev = third;
    fourth-> data =3;
    fourth-> next =fifth;

    fifth->prev = fourth;
    fifth-> data =3;
    fifth-> next = sixth;

    sixth->prev = fifth;
    sixth-> data = 4;
    sixth-> next = NULL;

    traverse(head);
    cout<<endl;
    head = Remove_Duplicates(head);
    traverse(head);
    return 0;

}