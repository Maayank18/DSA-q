#include<iostream>
// #include<map>
// using namespace std;

// struct node{
//     int data;
//     node * next;
// };


// int count_Ele_Loop( node * head){
//     map<node*,int> mpp;
//     node * temp = head;
//     int timer = 1;

//     while( temp != NULL){
//         if(mpp.find(temp) != mpp.end()){
//             int value = mpp[temp];
//             return (timer - value);
//         }else{
//             mpp[temp] = timer;
//             timer++;
//             temp = temp -> next;
//         }
//     }
//     return 0;
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

//     cout<<" the starting point in loop in LL is "<<count_Ele_Loop(head)<<endl;

//     return 0;
// }