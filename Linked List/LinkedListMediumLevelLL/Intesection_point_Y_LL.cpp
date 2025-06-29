// This problem basically aims in finding the first intersection point in a Y type 
// linked list
//eg.
//  1 -> 2 -> 3 
//             \
//              4 -> 5 -> 6 -> NULL
//             /
//      7 -> 8
// in this case the answer will be 4 and in case they are parallel and never collide 
// return the NULL value



// Extreme Brute force solution can be like we traverse firstly from first head in 
// Y road and store it in hashmap not the data but the node 
// Then while traversing the second y road if we encounter any already existing node we 
// can return that node and exit

// TIME COMPLEXITY -> O(length of head -> null ) + O(head2 -> point of intersection)
// space complexity -> O(head1's Length)

#include<iostream>
#include<map>
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

node * intersection_point( node * head1, node * head2){
    map<node*,int>mpp;
    node * temp1 = head1;

    while( temp1 != NULL){
        mpp[temp1] = 1;
        temp1 = temp1 -> next;
    }

    node * temp2 = head2;
    while(temp2 != NULL){
        if( mpp.find(temp2) != mpp.end()){
            return temp2;
        }else{
            temp2 = temp2 -> next;
        }
    }
    return NULL;
}


int main(){
    node* head1 = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* head2 = new node;
    node* fourth = new node;
    node* fifth = new node;
    node* sixth = new node;
    node* eighth = new node;


    // Initialize data and next pointers for each node
    head1->data = 10;
    head1->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    head2->data = 80;
    head2->next = eighth;

    eighth->data = 90;
    eighth->next = fourth;

    third->data = 40;
    third->next = fourth;
    
    fourth->data = 50;
    fourth->next = fifth;

    fifth->data = 60;
    fifth->next = sixth;

    sixth->data = 70;
    sixth->next = NULL;
    
    
    // reversingg(head);
    traversal(head1);
    cout<<endl;
    traversal(head2);
    cout<<endl;
    cout<<"The intersecting node is : " <<intersection_point(head1,head2)<<" and its data is : " <<intersection_point(head1,head2)->data<<endl;

    return 0;
}


// Better Solution infactit needed a VIEW POINT and we will wont need a external data type
// TIME COMPLEXITY -> O(len1) + O(len2) + O(differenec) + O(shorter length)
// SPACE COMPLEXITY -> O(1)


#include<iostream>
#include<map>
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

int lenght( node * head){
    int count = 0;
    node * temp = head;
    while( temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

node * intersection_point( node * head1, node * head2){
    node * t1 = head1;
    node * t2 = head2;
    int len1 = lenght(head1);
    int len2 = lenght(head2);

    int difference = abs(len1-len2);
    
    if( len1 > len2){
        for( int i = 0; i<difference; i++){
            t1 = t1 -> next;
        }
    }else{
        for( int i = 0; i<difference; i++){
            t2 = t2 -> next;
        }
    }

    while( t1 != NULL && t2 != NULL){
        if( t1 == t2){
            return t1;
        }else{
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
    }
    return NULL;
    
}


int main(){
    node* head1 = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* head2 = new node;
    node* fourth = new node;
    node* fifth = new node;
    node* sixth = new node;
    node* eighth = new node;


    // Initialize data and next pointers for each node
    head1->data = 10;
    head1->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    head2->data = 80;
    head2->next = eighth;

    eighth->data = 90;
    eighth->next = fourth;

    third->data = 40;
    third->next = fourth;
    
    fourth->data = 50;
    fourth->next = fifth;

    fifth->data = 60;
    fifth->next = sixth;

    sixth->data = 70;
    sixth->next = NULL;
    
    
    // reversingg(head);
    traversal(head1);
    cout<<endl;
    traversal(head2);
    cout<<endl;
    cout<<"The intersecting node is : " <<intersection_point(head1,head2)<<" and its data is : " <<intersection_point(head1,head2)->data<<endl;

    return 0;
}



// Optimal Approach -> What we basically gonna do is let 
// 1. there be temp 1 and temp 2
// 2. traverse both of them till one reaches the last node 
// 3. if temp1 reaches last node first point temp1 to head2
// 4. continuosly traverse again till temp2 recahes last node
// 5. when temp recahes last node connect it with head1
// 6. THROUGH THIS WE HAVE AUTOMATICALLY CROSSED THE DIFFERENCE AND AS SOON AS 
//    temp1 == temp2 return it 

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


node * intersection_point( node * head1, node * head2){
    node * temp1 = head1;
    node * temp2 = head2;

    while( temp1 != temp2){
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;

        if( temp1 == temp2) return temp1;

        if(temp1 -> next == NULL) temp1 = head2;
        if(temp2 -> next == NULL) temp2 = head1;

    }
    return NULL;
}


int main(){
    node* head1 = new node;
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* head2 = new node;
    node* fourth = new node;
    node* fifth = new node;
    node* sixth = new node;
    node* eighth = new node;


    // Initialize data and next pointers for each node
    head1->data = 10;
    head1->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    head2->data = 80;
    head2->next = eighth;

    eighth->data = 90;
    eighth->next = fourth;

    third->data = 40;
    third->next = fourth;
    
    fourth->data = 50;
    fourth->next = fifth;

    fifth->data = 60;
    fifth->next = sixth;

    sixth->data = 70;
    sixth->next = NULL;
    
    
    // reversingg(head);
    traversal(head1);
    cout<<endl;
    traversal(head2);
    cout<<endl;
    cout<<"The intersecting node is : " <<intersection_point(head1,head2)<<" and its data is : " <<intersection_point(head1,head2)->data<<endl;

    return 0;
}


