#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    vector<int> num(5); 
    for(int i =0; i<num.size(); i++){
        cin>>num[i];
    }

    map<int,int> m;
    for(int i =0; i<num.size();i++){
        int target = 11;
        int moreneeded = target - num[i];
        if(m.find(moreneeded)!=m.end()){
            cout << "Indices: " << m[moreneeded] << ", " << i << endl;
            return 0;
        }
        m[num[i]] = i;
    }
    cout<<" no pair found"<<endl;
    return 0;
}