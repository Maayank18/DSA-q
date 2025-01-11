// This problem aims to sort the data in the give linked list from low to high
// or high to low would be depending

//BRUTE FORCE SOLUTION IN WHICH WE GENERALLY TAKE ARR 
// PUSH ALL THE ELEMENTS IN ARR
// SORT ALL THE ELEMENTS IN ARRAY
// AND PUSH IT BACK IN THE LINKED LIST

// TIME COMPLXITY -> O(N) + time in sorting best O(nlogn) + O(N)
// SPACE COMPLEXITY -> O(N) as using additional space for vectors


// #include<iostream>
// #include<vector>
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

// void bubble_sort( vector<int> &arr){
//     int n = arr.size();
//     for( int i = 0; i<n-1; i++){
//         for( int j = 0; j<n-i-1; j++){
//             if( arr[j]>arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
// }

// node * sorting( node * head){
//     vector<int> arr;
//     node * temp = head;

//     while(temp != NULL){
//         arr.push_back(temp->data);
//         temp = temp -> next;
//     }
//     bubble_sort(arr); 

//     temp = head;
//     int i = 0;
//     while(temp != NULL){
//         temp->data = arr[i];
//         i++;
//         temp = temp -> next;
//     }   
//     return head;
// }


// int main(){
//     node* head = new node;
//     node* first = new node;
//     node* second = new node;
//     node* third = new node;

//     // Initialize data and next pointers for each node
//     head->data = 20;
//     head->next = first;

//     first->data = 30;
//     first->next = second;

//     second->data = 40;
//     second->next = third;

//     third->data = 10;
//     third->next = nullptr; // Last node points to nullptr

//     traversal(head);
//     cout<<endl;
//     head = sorting(head);
//     traversal(head);

//     return 0;
// }


// The better and optimal solution tries to break the linked list in two halfs and 
// then MERGE THE TWO SORTED LINKED LIST 
// It will definitely REDUCE THE SPACE COMPLEXITY AS NO EXTERNAL DATA STRUCTURE IS 
// USED FOR STORING


#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

// Function to traverse and print the linked list
void traversal(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to merge two sorted linked lists
node* mergeLL(node* left, node* right) {
    node* dummyNode = new node; // Create a dummy node
    node* temp = dummyNode;

    while (left != NULL && right != NULL) {
        if (left->data <= right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next; // Move the temp pointer forward
    }

    // Connect the remaining nodes
    if (left != NULL) {
        temp->next = left;
    } else {
        temp->next = right;
    }

    node* result = dummyNode->next; // Store the head of the merged list
    delete dummyNode; // Free the dummy node to prevent memory leaks
    return result;
}

// Function to find the middle node of the linked list
node* middle_fast_slow(node* head) {
    node* fast = head->next;
    node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Function to sort the linked list using merge sort
node* sortLL(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the middle of the list
    node* middle = middle_fast_slow(head);
    node* right = middle->next;
    middle->next = NULL; // Break the list into two halves
    node* left = head;

    // Recursively sort both halves
    left = sortLL(left);
    right = sortLL(right);

    // Merge the sorted halves
    return mergeLL(left, right);
}

int main() {
    // Create nodes
    node* head = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;

    // Initialize data and next pointers for each node
    head->data = 20;
    head->next = first;

    first->data = 30;
    first->next = second;

    second->data = 40;
    second->next = third;

    third->data = 10;
    third->next = nullptr; // Last node points to nullptr

    cout << "Original list: ";
    traversal(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted list: ";
    traversal(head);

    // Free allocated memory
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


