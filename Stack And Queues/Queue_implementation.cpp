#include<iostream>
using namespace std;

struct queue{
    int front;
    int rear;
    int size;
    int*arr;
};

int isFull(queue * q){
    if( q->rear == q->size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty (queue * q){
    if( q->rear == q->front){
        return 1;
    }else{
        return 0;
    }
}

int push( queue * q, int value){
    if(isFull(q)){
        cout<<" Sorry u cant add more "<<endl;
        return -1;
    }else{
        q->rear++;
        q->arr[q->rear] = value;
        return value;;
    }
}

int pop( queue * q){
    if(isEmpty(q)){
        cout<<" the queue is empty"<<endl;
        return -1;
    }else{
        q->front++;
        int value = q->arr[q->front];
        return value;
    }
}

int main(){
    queue * q = new queue;
    q->size = 10;
    q->rear = -1;
    q->front = -1;
    q->arr = new int[q->size];

    push(q,10);
    push(q,20);
    push(q,30);

    cout<<" the poped value is "<<pop(q)<<endl;
    return 0;
}