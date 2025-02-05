#include<iostream>
#include<vector>
using namespace std;

int CountingCoins( vector<int> arr, int value){
    int n = arr.size();
    int count = 0;
    for( int i = n-1; i>=0; i--){
        while(value>=arr[i]){
            value-= arr[i];
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,5,10,20,50,100,500,100};

    int ans = CountingCoins(arr,49);
    cout<<" the minimum coins required are : "<<ans<<endl;
    return 0;
}