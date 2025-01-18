// This particular question wants to implement the stack data structure and its 
// operations using queue
// STACK -> LIFO
// QUEUE -> FIFO

#include<iostream>
#include<queue>
using namespace std;

class myStack{
    queue<int> q;

    public:

    void push(int x){
        int s = q.size();
        q.push(x);
        for( int i = 0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int poppedValue = q.front();
        q.pop();
        return poppedValue;
    }

    int Top()
    {
        return q.front();
    }
    int Size()
    {
        return q.size();
    }

};

int main(){
    myStack s;
  s.push(3);
  s.push(2);
  s.push(4);
  s.push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();
}