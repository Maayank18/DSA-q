// This problem aims to sort the  array only containging 0 , 1 and 2 

//BRUT FORCE SOLUTION - where basically first traverse the whole list and store the
// count of 0 , 1, 2 and again while traversing will put back the numbers

// TIME COMPLEXITY -> O(2N)
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

node * sorting_0_1_2(node * head){
    node * temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    while( temp != NULL){
        if( temp->data == 0){
            count0++;
        }else if( temp->data == 1){
            count1++;
        }else{
            count2++;
        }
        temp = temp -> next;
    }

    temp = head;
    while( temp != NULL){
       if(count0){
        temp -> data = 0;
        count0--;
       }else if( count1){
        temp -> data = 1;
        count1--;
       }else{
        temp -> data = 2;
        count2--;
       }
       temp = temp -> next;
    }
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

    first->data = 0;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 1;
    third->next = nullptr; // Last node points to nullptr
    traversal(head);
    // traversal(head);
    cout<<endl;
    head = sorting_0_1_2(head);
    traversal(head);
    
    return 0;
}



// THE ABOVE SOLUTION WAS DEFINITELY USING TWO PASS APPROACH AND WE WILL TRY TO SOLVE
// IT WITH ONE PASS APPROACH 

// check for if there is only 0 and 2 UNDERSTAND HOW TO FORM THE CONNECTION

// TIME COMPLEXITY -> O(N)
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

node * sorting_0_1_2(node * head){
    node * temp = head;
    
    node * dummy_0 = new node;
    node* zero = dummy_0;

    node * dummy_1 = new node;
    node* one = dummy_1;

    node * dummy_2 = new node;
    node* two = dummy_2;

    while( temp != NULL){
        if( temp -> data == 0){
            zero->next = temp;
            zero = temp;
        }else if( temp -> data == 1){
            one -> next = temp;
            one = temp;
        }else{
            two -> next = temp;
            two = temp;
        }
        temp = temp -> next;
    }

    zero -> next = (dummy_1->next)? dummy_1->next : dummy_2-> next;
    one -> next = dummy_2-> next;
    two -> next = NULL;

    node * newHead = dummy_0->next;
    return newHead;
}



int main(){
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;

    // Initialize data and next pointers for each node
    head->data = 1;
    head->next = first;

    first->data = 0;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 1;
    third->next = nullptr; // Last node points to nullptr
    traversal(head);
    // traversal(head);
    cout<<endl;
    head = sorting_0_1_2(head);
    traversal(head);
    
    return 0;
}