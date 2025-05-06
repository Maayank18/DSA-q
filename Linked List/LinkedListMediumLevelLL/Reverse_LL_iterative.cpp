// BRUTE FORCE APPROACH INCLUDE - reversing the LL using the stack data structure 
// due to its LIFO property it helps in reversing 
// This use some external data space due to stack data strutcture


#include<iostream>
#include<stack>
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

void reversingg( node * head){

    if( head == NULL ){                 // base / edge case 
        return;
    }

    node * temp = head;
    stack<int> st;
    while( temp != NULL){
        st.push(temp->data);
        temp = temp -> next;
    }

    temp = head;
    while( temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp -> next;
    }
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
    // reversingg(head);
    traversal(head);

    return 0;
}



// The above solution was using some external data type and we should avoid it 
// as it was taking some external data structure that is stack
// we can may be think of reversing the links 


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

node * reversing( node * head){
   node * current = head;
   node * prev = NULL;
   while( current != NULL){
      node * front = current->next;
      current->next = prev;
      prev = current;
      current = front;
   }
   return prev;
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
    head = reversing(head);
    traversal(head);

    return 0;
}



// RECURSIVE APPROACH -> doing the same work of reversing to understand the approach
// breakdown of bigger into smaller problem 


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

node * reversing( node * head){
   if( head == NULL || head -> next == NULL){
    return head;
 }
    node * newhead = reversing(head->next);
    node * front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return newhead;
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
    head = reversing(head);
    traversal(head);

    return 0;
}