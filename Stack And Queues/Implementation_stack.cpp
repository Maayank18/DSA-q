// General implementation of stack using array , linked list and queues


// IMPLEMENTATION OF STACK USING ARRAYS

#include<iostream>
using namespace std;

struct stack{
    int top;
    int size;
    int*arr;
};

int isFull(stack *st){
    if( st->top == st->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty (stack * st){
    if( st->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int push( stack * st, int value){
    if(isFull(st)){
        cout<<" Sorry u cant add more "<<endl;
        return -1;
    }else{
        st->top++;
        st->arr[st->top] = value;
        return value;;
    }
}

int pop( stack * st){
    if(isEmpty(st)){
        cout<<" the stack is empty"<<endl;
        return -1;
    }else{
        int value = st->arr[st->top];
        st->top--;
        return value;
    }
}

int top(stack *st){
    return st->arr[st->top];
}

int main(){
    stack * st = new stack;
    st->top = -1;
    st->size = 10;
    st->arr = new int[st->size];

    push(st,10);
    push(st,20);
    push(st,30);

    cout<<" the poped element is "<<pop(st)<<endl;
    cout<<" the pushed elememnt is "<<push(st,40)<<endl;
    cout<<" ehich is top element "<<top(st)<<endl;
    return 0;

    
}