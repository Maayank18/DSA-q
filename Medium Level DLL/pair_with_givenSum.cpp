// This problem provides us with doubly linked list and want us to return the pair 
// of nodes whose sum == key 
// SORTED DOUBLY LINKED LIST


//BRUTE FORCE -> wecan check the nodes and sum with each other and find if their 
// exist any pair like that 
// TIME COMPLEXITY -> O(N^2)almost because of two while loops
// SPACE COMPLEXITY -> in my case i am using an vector so O(integer)
// where integer is number of pair

#include<iostream>
#include<vector>
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

vector<pair<int,int>> finding_pair( node * head, int key){
    vector<pair<int,int>> arr;
    node* temp1 = head;

    while( temp1 != NULL){
        node * temp2 = temp1 -> next;

        while( temp2 != NULL){
            if( temp1->data + temp2->data == key){
                arr.push_back({temp1->data,temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1 -> next;
    }
    return arr;
}
int main(){
    node * head = new node;
    node * first = new node;
    node * second = new node;
    node * third = new node;
    node * fourth = new node;
    node * fifth = new node;

    head-> prev = NULL;
    head-> data =1;
    head-> next = first;

    first->prev = head;
    first-> data =2;
    first-> next = second;

    second->prev = first;
    second-> data =3;
    second-> next = third;

    third->prev = second;
    third-> data = 4;
    third-> next = fourth;

    fourth->prev = third;
    fourth-> data = 7;
    fourth-> next = fifth;

    fifth->prev = fourth;
    fifth-> data = 9;
    fifth-> next = NULL;

    traverse(head);
    cout<<endl;

    vector<pair<int,int>> result = finding_pair(head,5);

    for( int i = 0; i<result.size(); i++){
        cout<<" the pair is :"<< result[i].first <<" and "<<result[i].second<<endl;
    }
    return 0;

}


// BETTER / OPTIMAL -> We know that the LIST is SORTED so in order to optimise 
// the time complexity we can use two pointer approach

#include<iostream>
#include<vector>
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
node * find_tail( node * head){
    node * temp = head;
    while(temp-> next != NULL ){
        temp = temp -> next;
    }
    return temp;
}

vector<pair<int,int>> finding_pair( node * head, int key){
    vector<pair<int,int>> arr;
    
    node * left = head;

    node * right = find_tail(head);
    while( left!= NULL && right != NULL && left!=right && left->prev!=right){
        if( left->data + right->data == key){
        arr.push_back({left->data,right->data});
        left = left -> next;
        right = right -> prev;
    }else if( left->data + right->data > key){
        right = right -> prev;
    }else{
        left = left -> next;
    }
    }
    return arr;
}
int main(){
    node * head = new node;
    node * first = new node;
    node * second = new node;
    node * third = new node;
    node * fourth = new node;
    node * fifth = new node;

    head-> prev = NULL;
    head-> data =1;
    head-> next = first;

    first->prev = head;
    first-> data =2;
    first-> next = second;

    second->prev = first;
    second-> data =3;
    second-> next = third;

    third->prev = second;
    third-> data = 4;
    third-> next = fourth;

    fourth->prev = third;
    fourth-> data = 7;
    fourth-> next = fifth;

    fifth->prev = fourth;
    fifth-> data = 9;
    fifth-> next = NULL;

    traverse(head);
    cout<<endl;

    vector<pair<int,int>> result = finding_pair(head,5);

    for( int i = 0; i<result.size(); i++){
        cout<<" the pair is :"<< result[i].first <<" and "<<result[i].second<<endl;
    }
    return 0;

}