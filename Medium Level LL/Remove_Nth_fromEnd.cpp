// This problem helps us to find the nth node from end 

//BRUTE FORCE SOLUTION -> find the length of LL and stop at one step before the node 
// which is to be deleted and make the new connection

// TIME COMPLEXITY -> O(length) + O( length -n)
// Space complexity -> O(1)


// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     node * next;
// };

// void traversal(node * head){
//     node * temp = head;
//     while( temp != NULL){
//         cout<<temp -> data<<" ";
//         temp = temp -> next;
//     }
// }

// int total_nodes( node * head){
//     node * temp = head;
//     int counter = 0;
//     while( temp != NULL){
//         temp = temp -> next;
//         counter++;
//     }
//     return counter;
// }

// node * Remove_nth( node * head, int n){
//     int count = total_nodes(head);
    
//     if( count == n){
//         node * newHead = head -> next;
//         return newHead; 
//     }


//     int result = count - n;
//     node * temp = head;
//     int i = 1;

//     while( i<result){
//         temp = temp -> next;
//         i++;
//     }
//         node * deletenode = temp -> next;
//         temp -> next = temp -> next -> next;
//         free(deletenode);
//         return head;
// }

// int main(){
//     node* head = new node;
//     node* first = new node;
//     node* second = new node;
//     node* third = new node;

//     // Initialize data and next pointers for each node
//     head->data = 10;
//     head->next = first;

//     first->data = 20;
//     first->next = second;

//     second->data = 30;
//     second->next = third;

//     third->data = 40;
//     third->next = nullptr; // Last node points to nullptr

//     traversal(head);
//     cout<<endl;
//     head = Remove_nth(head,3);
//     traversal(head);


//     return 0;
// }



// Btter solution will include something like fast and slow pointer approach 
// so first of all we will take fast and move it n node where n is number of node
// to be deleted at end
// when the fast reaches that n point from start we will simultaneously 
// move fast and slow by one 

// TIME COMPLEXITY -> O(len)
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

int total_nodes( node * head){
    node * temp = head;
    int counter = 0;
    while( temp != NULL){
        temp = temp -> next;
        counter++;
    }
    return counter;
}

node * Remove_nth( node * head, int n){
    node * fast = head;
    for( int i = 0; i<n; i++){
        fast = fast -> next;
    }

    node * slow = head;
    while( fast != NULL && fast -> next != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }
    node * delnode = slow -> next;
    slow -> next = slow -> next -> next;
    free(delnode);
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
    third->next = nullptr; // Last node points to nullptr

    traversal(head);
    cout<<endl;
    head = Remove_nth(head,3);
    traversal(head);


    return 0;
}

