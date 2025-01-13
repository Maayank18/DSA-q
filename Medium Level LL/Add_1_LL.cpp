// This particular question aims to find the linked list after adding 1 to its data
// eg. linked list is :-  1 -> 5 -> 9
// Add 1 to data that is 159+1 = 160
// Return the Linked List 1 -> 6 -> 0

// TIME COMPLEXITY -> O(3N)
// SPACE COMPLEXITY -> O(1)

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

node * reverse ( node * head){
    node * current = head;
    node * prev = NULL;
    while( current != NULL){
        node * front = current -> next;
        current -> next = prev;
        prev = current;
        current = front;
    }
    return prev;
}

node * Add_1(node * head){
    node * temp = head;
    head = reverse(head);

    temp = head;
    int carry = 1;
    while( temp != NULL){
        temp->data = temp->data + carry;

        if(temp->data < 10){
            carry = 0;
            break;
        }else{
            carry = 1;
            temp->data = 0;
        }

        // incase all nodes are over and we still have a carry
        if(temp->next == NULL && carry == 1){
        node * newNode = new node;
        newNode->data = carry;
        newNode->next = NULL;
        temp->next = newNode;
        carry = 0;
        }
        temp = temp -> next;
    }

    head = reverse(head);
    return head;
}



int main(){
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;

    // Initialize data and next pointers for each node
    head->data = 1;
    head->next = first;

    first->data = 6;
    first->next = second;

    second->data = 0;
    second->next = third;

    third->data = 9;
    third->next = nullptr; // Last node points to nullptr
    traversal(head);
    // traversal(head);
    cout<<endl;
    head = Add_1(head);
    traversal(head);
    
    return 0;
}


// In order to further optimise the solution we instead of reversing and applying 
// logic we can use recursion as in recursion we will land at last node and 
// easily apply our logics


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

node * reverse ( node * head){
    node * current = head;
    node * prev = NULL;
    while( current != NULL){
        node * front = current -> next;
        current -> next = prev;
        prev = current;
        current = front;
    }
    return prev;
}

node * Add_1(node * head){

    if(head == NULL){
        return 1;
    }

    
}



int main(){
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;

    // Initialize data and next pointers for each node
    head->data = 1;
    head->next = first;

    first->data = 6;
    first->next = second;

    second->data = 0;
    second->next = third;

    third->data = 9;
    third->next = nullptr; // Last node points to nullptr
    traversal(head);
    // traversal(head);
    cout<<endl;
    head = Add_1(head);
    traversal(head);
    
    return 0;
}