#include<iostream>
#include<vector>
using namespace std;

bool AllServed(vector<int> arr){
    int n = arr.size();
    int five = 0;
    int ten = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == 5){
            five++;
        }else if( arr[i] == 10){
            if(five){
                ten++;
                five--;
            }else{
                return false;
            }
        }else{
            if( five && ten){
                five--;
                ten--;
            }else if(five>=3){
                five -= 3*five;
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<int> arr = {5,5,10,10,20};
    bool result = AllServed(arr);
    cout<<" are all customer served : "<<result<<endl;
    return 0;
}