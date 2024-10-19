#include<iostream>
using namespace std;

void a(int i){
    if(i>4){
        return;
    }
    cout<<"mayank"<<endl;
    
    a(i+1);
}
int main(){
    int i = 0;
    a(i);
    return 0;
}