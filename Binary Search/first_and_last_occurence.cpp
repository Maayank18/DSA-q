// basically it particulalry tells about the occurences of a target elment consider 
// arr[ 1,2,4,6] here t = 8, so as nuo. dont exist it will return {-1,-1}
// arr[ 1,2,3,8] here t = 8, so as it as one no. so it will return {3.3}
// consider arr[1,8,2,8] here t = 8, so return is {1,3}

// #include<iostream>
// using namespace std;

// pair<int,int> find( int arr[], int n, int t){
//     int first = -1;
//     int last = -1;
//     for(int i = 0; i<n; i++){
//         if(arr[i] == t){
//             if( first == -1){
//                 first = i;
//             }
//             last = i;
//         }
//     }
//     return make_pair(first,last);
// }

// int main(){
//     int n;
//     cout<<" enter the size of array : ";
//     cin>>n;

//     int x;
//     cout<<" enter the number whose index is to be found : ";
//     cin>>x;

//     int arr[n];
//     for( int i = 0; i<n; i++){
//         cin>>arr[i];
//     }
//     cout<<endl;

//     pair<int,int> first_last =  find(arr,n,x);


//     cout<<" the first and last element are  : "<<first_last.first<<" and "<< first_last.second<<endl;

//     return 0;
// }


// another method is we can foudn the lwer bound to find the first occurence 
// and w ecan find the (upper bound - 1)** to find the last occurence 

// we can use to return a pair of indices so,

//---------------------------------------------------------------------------------------

// if( lowerbound_indices == n(hypothetical index ) || arr[lowerbound] ! = t){
//     return make_pair (-1,-1);
// }else{
//     return make_pair (lowerbound, upperbound-1);
// }




// another case can be when th interviewer ask not to user upper bound or the lower bound 
// in that case we gonna write two different programs involvinf , firstlt finding the 
// frist occurence using first fucntion amd last occurence using the last function

#include<iostream>
using namespace std;

int first_o( int arr[], int n, int t){
    int low = 0;
    int high = n-1;
    int f = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == t){
            f = mid;
            high = mid - 1;
        }
        else if( arr[mid] > t){
            high = mid  - 1;
        }
        else{
            low  = mid + 1;
        }
    }
    return f;
}

int last_o( int arr[], int n, int t){
    int low = 0;
    int high = n-1;
    int l = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == t){
            l = mid;
            low = mid + 1;
        }
        else if( arr[mid] < t){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return l;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int t;
    cout<<" enter the target element : ";
    cin>>t;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;

    int first =  first_o(arr,n,t);
    int last = last_o(arr,n,t);

    cout<<" the first and the last occurence is : "<<first<<" and "<<last<<endl;
    return 0;
}