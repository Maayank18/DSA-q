// Extreme brute force solution include using of stack data structure as it use LIFO
// let our linked list be 1 -> 2 -> 3 -> 4 if we pus elements in stack 
// they will go 1,2,3,4 and when we retrieve them we will get 4,3,2,1
// as LIFO - LAST IN FIRST OUT



// #include<iostream>
// #include<stack>
// using namespace std;

// struct node{
//     int data;
//     node * next;
//     node * prev;
    
// };

// node* traverse( node* head){
//     node* temp = head;
//     while( temp!=NULL){
//         cout<< temp->data<<" ";
//         temp = temp-> next;
//     }
// }

// void reversing_DLL(node* head){
//     stack<int> st;
//     node * temp = head;
//     while( temp != NULL){
//         st.push(temp->data);
//         temp = temp -> next;
//     }

//     temp = head;
//     while( temp != NULL){
//         temp -> data = st.top();
//         st.pop();
//         temp = temp->next;
//     }
// }

// int main(){
//     node * head = new node;
//     node * first = new node;
//     node * second = new node;
//     node * third = new node;

//     head-> prev = NULL;
//     head-> data =10;
//     head-> next = first;

//     first->prev = head;
//     first-> data =20;
//     first-> next = second;

//     second->prev = first;
//     second-> data =30;
//     second-> next = third;

//     third->prev = second;
//     third-> data =40;
//     third-> next = NULL;

//     traverse(head);
//     cout<<endl;
//     reversing_DLL(head);
//     traverse(head);

//     return 0;

// }




// optimal / better solution will use a concept of snapping or we can say it will use
// changing the DIRECTION OF LINKS AND OUR WORK WILL BE DONE 


#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
    node * prev;
    
};

node* traverse( node* head){
    node* temp = head;
    while( temp!=NULL){
        cout<< temp->data<<" ";
        temp = temp-> next;
    }
}

node * ReverseTheDLL ( node * head){
    node * current = head;
    node * prev = NULL;

    while(current!=NULL){
        prev = current -> prev;
        current -> prev = current -> next;
        current -> next = prev;

        current = current -> prev;
    }
    return prev->prev;
}

int main(){
    node * head = new node;
    node * first = new node;
    node * second = new node;
    node * third = new node;

    head-> prev = NULL;
    head-> data =10;
    head-> next = first;

    first->prev = head;
    first-> data =20;
    first-> next = second;

    second->prev = first;
    second-> data =30;
    second-> next = third;

    third->prev = second;
    third-> data =40;
    third-> next = NULL;

    traverse(head);
    cout<<endl;
    head = ReverseTheDLL(head);
    traverse(head);
    return 0;

}