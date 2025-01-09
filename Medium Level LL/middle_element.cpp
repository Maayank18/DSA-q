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

// int count( node* head){
//     node * ptr = head;
//     int count = 0;
//     while( ptr != NULL){
//         count++;
//         ptr = ptr -> next;
//     }
//     return count;
// }

// int function( node* head){
//     int middle = (count(head))/2;
//     node * move = head;
//     for (int i = 0; i < middle; i++) { // Move `middle` steps from the head
//         move = move->next;
//     }
//     return move->data;
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
//     int numberOFelements = count(head);
//     cout<<" number of nodes are : "<<numberOFelements<<endl;
//     int middle_element = function(head);
//     cout<<" the middle element is : "<<middle_element<<endl;

//     return 0;
// }



// another method which may be better or be brute can be this which will be taking 
// a TIME COMPLEXITY OF O(n) + O(n/2)

// #include<iostream>
// using namespace std;

// struct node{
//     int data;
//     node * next;
// };


// int traversal(node * head){
//     node * temp = head;
//     while( temp != NULL){
//         cout<<temp -> data<<" ";
//         temp = temp -> next;
//     }
// }

// int medianNODE(node *head) {
//     if (head == NULL) { // Handle the case of an empty list
//         return -1; // or throw an exception, based on your design
//     }

//     node *temp = head;
//     int count = 0;

//     // Count the total number of nodes
//     while (temp != NULL) {
//         temp = temp->next;
//         count++;
//     }

//     // Calculate the middle index
//     int middle = count / 2; // (0-based index for middle node)

//     temp = head; // Reset temp to head

//     // Traverse to the middle node
//     for (int i = 0; i < middle; i++) {
//         temp = temp->next;
//     }

//     // Return the data of the middle node
//     return temp->data;
// }

// node * medianNODE( node * head){
//     node * temp = head;
//     int count = 0;
//     while( temp != NULL){
//         temp = temp -> next;
//         count++;
//     }
    
//     int middle = (count/2);
//     temp = head;
//     while( temp != head){
//         middle = middle-1;
//         if(middle == 0){
//             break;
//         }
//         temp = temp -> next;
//     }
//     return temp;
// }



// int main(){
//     node* head = new node;
//     node* first = new node;
//     node* second = new node;
//     node* third = new node;

    // Initialize data and next pointers for each node
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

//     cout<<" the median node is : "<<medianNODE(head)<<endl;
//     return 0;
// }




// OPTIMAL SOLUTION IS UNIQUE HAVING A FAST AND SLOW POINTER APPROACH
//  let fast and slow both be pointing at first node
// and incremenet the fast by 2 AND slow by 1 
// till the fast will reach end node or null our slow pointer will reach somewhere 
// in middle thats the approach

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

int middle_fast_slow(node * head){
    node * fast = head;
    node * slow = head;

    while( fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow -> next;
    }
    return slow->data;
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

    cout<<" the middle node is "<<middle_fast_slow(head)<<endl;

    return 0;
}