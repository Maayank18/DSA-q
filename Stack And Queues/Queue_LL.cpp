#include<iostream>
using namespace std;

struct QueueNode {
    QueueNode * next;
    int data;

    QueueNode( int value ){
        data = value;
        next = NULL;
    }
};

struct Queue{
    QueueNode * front  = NULL;
    QueueNode * rear = NULL;
    int size;
    int capacity;

    Queue(int maxCapacity){
        front  = NULL;
        rear = NULL;
        size = 0;
        capacity = maxCapacity;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty(){
        return rear == front;
    }

    void pushInQueue(int value){
        QueueNode * element = new QueueNode(value);

        if(isFull()){
            cout<<" queue overflow ";
        }else{
            if(front == NULL){
                front = element;
                rear = element;
            }else{
                rear->next = element;
                rear = element;
            }
            cout<<value<<" is enqueued ";
            size++;
        }
    }

    int popFromQueue(){
        if(isEmpty()){
            cout<<" queue underflow ";
            return -1;
        }else{
            QueueNode * temp = front;
            int poppedValue = front->data;
            front = front -> next;
            delete temp;
            cout<<" the popped value is "<<poppedValue<<endl;
            return poppedValue;
        }

    }
};

int main(){
    Queue * q = new Queue(5);

    q->pushInQueue(10);
    q->pushInQueue(20);
    q->pushInQueue(30);
    cout<<q->popFromQueue()<<endl;
    return 0;
}