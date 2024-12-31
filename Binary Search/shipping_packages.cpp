// problem ask the LEAST PACKAGING REQUIRED TO SHIP IT IN D DAYS
// we would be given packages , days withing which they ae needed to be shipped
// find the least packaging
// ships runs once per day and we are given weights in terms of array and find 
// minimum weight it would carry once a day so that all weigts are shipped within d days 

// eg [1,2,3,4,5,6,7,8,9,10]

// something to observe that capacity must(minimum) be equal to max weight of product 
// otherwise some of the leftover wont be able to ship consider example of 
// if capacity is 8 , then we wont be able to ship 9 and 10

// also the range of capacity will be from [ max element to sum of all ]

// return -1 if cant be shipped;

#include<iostream>
using namespace std;

int sum_of_array( int arr[], int n){
    int sum = 0;
    for( int i = 0; i<n; i++){
        sum+= arr[i];
    }
    return sum;
}

int max_in_array( int arr[], int n){
    int max = arr[0];
    for( int i = 1; i<n ; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}



int minimum_num_days( int arr[], int n, int capacity){

    int day = 1;
    int weight = 0;

    for(int i = 0; i<n; i++){

        if(weight+arr[i] > capacity){
            day++;
            weight = arr[i];
        }else{
            weight += arr[i];
        }
    }
    return day;
}

int least_weights( int arr[], int n, int min_day){
    int max_capacity = sum_of_array(arr,n);
    int min_capacity = max_in_array(arr,n);

    for( int i = min_capacity; i<= max_capacity; i++){
        if(minimum_num_days(arr,n,i) <= min_day){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<" enter the number of products in ships : ";
    cin>>n;

    int arr[n];
    
    cout<<" enter the products : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int min_day;
    cout<<" minimum days within which order must be shipped : ";
    cin>>min_day;

    int min_capacity = least_weights(arr,n,min_day);

    cout<<" the least load needed is : "<<min_capacity<<endl;

    return 0;
}


// optimal approach - a binary search 

#include<iostream>
using namespace std;

int sum_of_array( int arr[], int n){
    int sum = 0;
    for( int i = 0; i<n; i++){
        sum+= arr[i];
    }
    return sum;
}

int max_in_array( int arr[], int n){
    int max = arr[0];
    for( int i = 1; i<n ; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int least_weights( int arr[], int n, int min_day){
     int high = sum_of_array(arr,n);
     int low = max_in_array(arr,n);

     while(low<=high){
        int mid = low + (high-low)/2;

        
     }
}


int main(){
    int n;
    cout<<" enter the number of products in ships : ";
    cin>>n;

    int arr[n];
    
    cout<<" enter the products : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int min_day;
    cout<<" minimum days within which order must be shipped : ";
    cin>>min_day;

    int min_capacity = least_weights(arr,n,min_day);

    cout<<" the least load needed is : "<<min_capacity<<endl;

    return 0;
}