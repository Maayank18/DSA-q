// this is a brute force solution which would be having a time complexity of O(N) 
// and it would be taking a space complexity of O(1) beacuse we are not using any 
// extra space for it  ( Only case if we need to rotate by 1 space )
#include <iostream>
using namespace std;

void rotate(int arr[], int n){
    int temp = arr[0];
    for( int i = 1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return;
}

int main() {
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;
    cout<<" original array :";
    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    
    
    rotate(arr,n);
    cout<<" array after rotating  : ";
      for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}

// this is a average case which would be having a time comlexity of O(d)+O(n-d)+O(d) = O(n+d)
// and a space complexity of O(d) for storing elelme ts to be shifted
// not a better solution but kind of brute force solution 

#include<iostream>
#include<vector>
using namespace std;

void rotate_d( vector<int> &num, int n, int d){
    vector<int> temp;
    d = d % n;

    for(int i = 0; i<d; i++){
        temp.push_back(num[i]);
    }

    for( int i = d; i<n; i++){
        num[i-d] = num[i];
    }

    for(int i = n-d; i<n; i++){
        num[i] =  temp[i-(n-d)];
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;
    int d;
    cout<<" enter the number of spaces you want to shift : ";
    cin>>d;

    vector<int> num(n);
    for( int i = 0; i<num.size(); i++){
        cin>>num[i];
    }
    cout<<" Original array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

    rotate_d(num,n,d);

    cout<<" after rotating array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    return 0;
}

// this particular wont be having any better solution but an optimal solution 
// having a time complexity of O(2n) = O(n) and as we wont be using any exra space 
// it will have O(1) space complexity 
// here we gonna use reversing the both sub arrays and finally reversiing the whole 
// arrays and the outcome will be same 
// ( try li use array instead of vector )

#include<iostream>
using namespace std;

void reverse(int arr[], int low, int high){
    while(low<=high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

void rotate( int arr[], int n, int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;
    int d;
    cout<<" the number of spaces to be shifted : ";
    cin>>d;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" original array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    rotate(arr,n,d);
    cout<<" after rotation array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}