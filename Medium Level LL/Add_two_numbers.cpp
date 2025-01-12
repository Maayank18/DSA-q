// This problem basically aims to provide us with two linked list and return its sum
// ( make sure of any carry if its their )

//BRUTE FORCE SOLUTION


#include <iostream>
using namespace std;

// Definition of the linked list node
struct node {
    int data;
    node* next;
};

// Function to traverse and print a linked list
void traversal(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse a linked list
node* reverse(node* head) {
    node* current = head;
    node* prev = NULL;

    while (current != NULL) {
        node* front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }
    return prev;
}

// Function to add two numbers represented as linked lists
node* Add_2_LL(node* head1, node* head2) {
    // Reverse both input linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);

    node* temp1 = head1;
    node* temp2 = head2;

    // Create a dummy node to build the result list
    node* DummyNode = new node;
    DummyNode->next = NULL;
    node* temp3 = DummyNode;

    int carry = 0;

    // Traverse both lists and add corresponding digits
    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        int sum = carry; // Start with the carry value

        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        // Create a new node for the current digit of the sum
        node* newNode = new node;
        newNode->data = sum % 10; // Extract the last digit
        newNode->next = NULL;

        carry = sum / 10; // Update the carry

        // Append the new node to the result list
        temp3->next = newNode;
        temp3 = temp3->next;
    }

    // Reverse the result list back to the correct order
    return reverse(DummyNode->next);
}

int main() {
    // Creating the first linked list: 6 -> 4 -> 2
    node* head1 = new node;
    node* first = new node;
    node* second = new node;

    head1->data = 6;
    head1->next = first;

    first->data = 4;
    first->next = second;

    second->data = 2;
    second->next = NULL;

    // Creating the second linked list: 7 -> 8 -> 3
    node* head2 = new node;
    node* eighth = new node;
    node* ninth = new node;

    head2->data = 7;
    head2->next = eighth;

    eighth->data = 8;
    eighth->next = ninth;

    ninth->data = 3;
    ninth->next = NULL;

    // Display the input lists
    cout << "First List: ";
    traversal(head1);
    cout << "Second List: ";
    traversal(head2);

    // Add the two linked lists
    node* result = Add_2_LL(head1, head2);

    // Display the result list
    cout << "Result List: ";
    traversal(result);

    return 0;
}

