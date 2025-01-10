// this code help in understanding whether the given linked list is pallindrome or not


//BRUTE FORCE SOLUTION -> we can simpley reverse the linked list and check if the 
// elements are same after reversal , being brute force approach it will be taking
// stack data structure
// TIME COMPLEXITY -> O(2N)
// SPACE COMPLLEXITY -> O(N)


// #include<iostream>
// #include<stack>
// using namespace std;

// struct node{
//     int data;
//     node * next;
// };

// bool check_if_pallindrome( node * head){
//     node * temp = head;
//     stack<int> st;

//     while(temp!=NULL){
//         st.push(temp->data);
//         temp = temp -> next;
//     }

//     temp = head;
//     while( temp != NULL){
//         if(temp->data != st.top()){
//             return false;
//         }else{
//             st.pop();
//             temp = temp -> next;
//         }
//     }
//     return true;
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

//     second->data = 20;
//     second->next = third;

//     third->data = 10;
//     third->next = nullptr; // Last node points to nullptr

//     // traversal(head);
//     cout<<endl;
//     cout<<" Is the linked List pallindrome : "<<check_if_pallindrome(head)<<endl;
//     return 0;
// }


// BETTER SOLUTION IS SOMEWHAT WHERE WE DONT DONT EXTERNAL DATA STRUCTURE 
// 1.approach can be divide linked list in two halves 
// 2.reverse the second half of linked list 
// 3.and check the first halve with the second half
// 3. if same return true else false

// TIME COMPLEXITY -> overall O(2N)
// SPACE COMPLEXITY -> O(1)

#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node * next;
};

node * reverse( node * head2){
    node * current = head2;
    node * prev = NULL;
    while( current != NULL){
        node * front = current -> next;
        current -> next = prev;
        prev = current;
        current = front; 
    }
    return prev;
}

bool checkIf_pallindrome( node * head){
    node * slow = head;
    node * fast = head;

    while( fast -> next != NULL && fast -> next-> next != NULL){
        slow = slow -> next;
        fast = fast -> next-> next;
    }
    node * second_head = reverse(slow->next);
    node * first_head = head;
    node * temp_second_head = second_head; // just to store it

    while( second_head != NULL){
        if( first_head->data != second_head->data){
            reverse(temp_second_head);
            return false;
        }else{
            first_head = first_head -> next;
            second_head = second_head -> next;
        }
    }
    reverse(temp_second_head);
    return true;
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

    second->data = 20;
    second->next = third;

    third->data = 10;
    third->next = nullptr; // Last node points to nullptr

    // traversal(head);
    cout<<endl;
    cout<<" check if it is pallindrome :  "<<checkIf_pallindrome(head)<<endl;
    
    return 0;
}