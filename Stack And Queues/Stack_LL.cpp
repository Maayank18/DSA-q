#include<iostream>
using namespace std;

struct stackNode{
    stackNode * next;
    int data;

    stackNode(int value){
        data = value;
        stackNode * next = NULL;
    }
};

struct stack{
    stackNode * top;;
    int size;
    int capacity;

    stack(int maxCapacity){
        stackNode * top = NULL;
        size = 0;
        capacity = maxCapacity;
    }


    bool isFull(){
        return size == capacity-1;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void pushInStack( int value){
        if(isFull()){
            cout<<" sorry the stack is full";
        }else{
            stackNode * element = new stackNode(value);
            element->data = value;
            element->next = top;
            top = element;
            size++;
            cout<<" the node pushed is of value :"<< value<<endl;
        }
    }

    int popFromStack(){
        if(isEmpty()){
            cout<<" sorry nothing can be popped ";
        }else{
            int poppedValue = top -> data ;
            stackNode * temp = top;
            top = top -> next;
            delete temp;
            size--;
            cout<<" the popped value is "<<poppedValue<<endl;
        }
    }
};


int main(){
    stack * s = new stack(5);

    s->pushInStack(10);
    s->pushInStack(20);
    s->pushInStack(30);
    cout<<s->popFromStack()<<endl;
    return 0;
}


 

