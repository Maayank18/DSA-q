#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

// node* convertArrToLL( int arr[], int n){
//     node * head = new node(arr[0]);
//     node * mover = head;

//     for( int i = 0; i<n; i++){
//         node * temp = new node(arr[i]);
//         mover -> next = temp;
//         mover = temp;
//     }
//     return head;
// }

void traversal(node * head){
    node * temp = head;
    while( temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

int lengthOfNode( node * head){
    node * temp = head;
    int count = 0;
    while( temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
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

    cout<<lengthOfNode(head)<<endl;
    return 0;
}