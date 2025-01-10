// this particular question aims to find the the starting point from where the loop 
// or cycle of linked list has started


//BRUTE FORCE SOLUTION INCLUDE -> HASHING TO KEEP THE COUNTER AND AS SOON AS THE 
// NODE RE APPEARS IT WILL RETURN US THE NODE

// #include<iostream>
// #include<map>
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

// int starting_loop( node * head){
//     map<node*,int> mpp;
//     node * temp = head;

//     while( temp != NULL){
//         if( mpp.find(temp) != mpp.end()){
//             return temp->data;
//         }else{
//             mpp[temp] = 1;
//             temp = temp -> next;
//         }
//     }
//     return -1;
// }



// int main(){
//     node* head = new node;
//     node* first = new node;
//     node* second = new node;
//     node* third = new node;
//     node* fourth = new node;
//     node* fifth = new node;


//     // Initialize data and next pointers for each node
//     head->data = 10;
//     head->next = first;

//     first->data = 20;
//     first->next = second;

//     second->data = 30;
//     second->next = third;

//     third->data = 40;
//     third->next = fourth; 

//     fourth->data = 50;
//     fourth->next = fifth;

//     fifth->data = 60;
//     fifth->next = third;

//     cout<<endl;

//     cout<<" the starting point in loop in LL is "<<starting_loop(head)<<endl;

//     return 0;
// }


// Inorder to OPTIMISE TH EALGORITHM we would be using hare and tortoise algorithm
// 1. detecting the loop ( if no loop no starting point ) 
// 2. if loop exist the starting point also exist
// IF the loop exist what we will do is keep the fast pointer at point of collision and 
// slow pointer at starting and now both will move one one point ahead 
// and whereever they collide again that would be our starting point of LOOP


#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
};


int optimised_starting_loop(node*head){
    node * slow = head;
    node* fast = head;
    while( fast != NULL && fast->next !=NULL){
        slow = slow ->next;
        fast = fast ->next->next;
        if( slow == fast){
            slow = head;
            while( slow != fast){
                slow = slow -> next;
                fast = fast -> next;
            }
            return slow->data;
        }
    }
    return NULL;
}



int main(){
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node;
    node* fifth = new node;


    // Initialize data and next pointers for each node
    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth; 

    fourth->data = 50;
    fourth->next = fifth;

    fifth->data = 60;
    fifth->next = third;

    cout<<endl;

    cout<<" the starting point using optimal approach is "<<optimised_starting_loop(head)<<endl;

    

    return 0;
}