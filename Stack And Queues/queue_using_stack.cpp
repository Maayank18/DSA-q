// in this problem i basically have to implement a queue using a stack data 
// data structure

// Brute Force Solution - using two stacks to carry out the fucntion
// TIME COMPLEXITY -> O(2N)
//SPACE COMPLEXITY -> O(2N)

// #include<iostream>
// #include<stack>
// using namespace std;

// class myQueue{
//     stack<int> s1,s2;

//     public:
//     void push( int value ){
//         while(s1.size()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s2.push(value);

//         while(s2.size()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int pop(){
//         int popped = s1.top();
//         s1.pop();
//         return popped;
//     }

// };

// int main(){
//     myQueue q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     cout<<" the popped element is "<<q.pop()<<endl;
// }



// As the brute force solution is taking much more time and emphasis on the push
// operation another approach can be emphasis more on pop and top operation

#include<iostream>
#include<stack>
using namespace std;

class myQueue{
    stack<int> s1,s2;

    public:
    void push( int value ){
        s1.push(value);
    }

    int pop(){
        if(!s2.empty()){
            s2.pop();
        }else{
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            int popped = s2.top();
            s2.pop();
            return popped;
        }
    }
};

int main(){
    myQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<" the popped element is "<<q.pop()<<endl;
}

