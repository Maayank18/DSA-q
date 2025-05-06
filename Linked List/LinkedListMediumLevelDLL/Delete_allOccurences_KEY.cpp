// this particular problem provies a doubly linked list and we have to remove all the key
// eg. if key = 10, then we have to remove all the 10's from doubly linked list 
// and return the remaining list


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

node * removing_all_occurences_of_key( node * head, int key){
    node * temp = head;

    while(temp != NULL){
        if( temp -> data == key){
            if( temp == head){
                head = head ->next;
            }

            node * nextnode = temp -> next;
            node * prevnode = temp -> prev;
            if(nextnode) nextnode-> prev = prevnode;
            if(prevnode) prevnode -> next = nextnode;

            free(temp);
            temp = nextnode;
        }else{
            temp = temp->next;
        }
    }
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
    second-> data =10;
    second-> next = third;

    third->prev = second;
    third-> data =30;
    third-> next = NULL;

    traverse(head);
    cout<<endl;
    head = removing_all_occurences_of_key(head,10);
    traverse(head);
    return 0;

}