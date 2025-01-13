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


// BRUTE FORCE SOLUTION - somehow solving the question without thinking of oprimisation;

#include<iostream>
using namespace std;

int sum_of_arr( int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+= arr[i];
    }
    return sum;
}

int max_element_of_arrar( int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int calculating_days( int arr[], int n, int capacity){
    int day = 1;
    int load = 0;

    for( int i = 0; i<n; i++){
        if( load + arr[i] > capacity){
            day++;
            load = arr[i];
        }else{
            load+=arr[i];
        }
    }
    return day;
}

int calculating_minimum_load( int arr[], int n, int minimumDAYS){
    int maxLoad = sum_of_arr(arr,n);
    int minLoad = max_element_of_arrar(arr,n);

    for( int capacity = minLoad; capacity<=maxLoad; capacity++){
        if( calculating_days(arr,n,capacity) <= minimumDAYS){
            return capacity;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<" the number of parcels to be delivered : ";
    cin>>n;

    int arr[n];
    cout<<" enter the weights of each parcel : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int minimumDAYS;
    cout<<" enter the minimum days in which these are to be delivered : ";
    cin>>minimumDAYS;

    int minimum_load = calculating_minimum_load(arr,n,minimumDAYS);

    cout<<" the minimum number of load required is : "<<minimum_load<<endl;

    return 0;
}

// talkjing about the optimal approach it woulf take in consideration 
// BINARY SEARCH AS TILL SOME POINT ANSWER IS VALID AND AFTER THAT INVALID

#include<iostream>
using namespace std;

int sum_of_arr( int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum+= arr[i];
    }
    return sum;
}

int max_element_of_arrar( int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int calculating_days( int arr[], int n, int mid){
    int day = 1;
    int load = 0;

    for( int i = 0; i<n; i++){
        if( load + arr[i] > mid){
            day++;
            load = arr[i];
        }else{
            load+=arr[i];
        }
    }
    return day;
}


int calculating_minimum_load(int arr[], int n, int minimumDAYS){
    int low = max_element_of_arrar(arr,n);
    int high = sum_of_arr(arr,n);
    int answer = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(calculating_days(arr,n,mid) <= minimumDAYS){
            answer = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return answer;
}

int main(){
    int n;
    cout<<" the number of parcels to be delivered : ";
    cin>>n;

    int arr[n];
    cout<<" enter the weights of each parcel : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int minimumDAYS;
    cout<<" enter the minimum days in which these are to be delivered : ";
    cin>>minimumDAYS;

    int minimum_load = calculating_minimum_load(arr,n,minimumDAYS);

    cout<<" the minimum number of load required is : "<<minimum_load<<endl;

    return 0;
}