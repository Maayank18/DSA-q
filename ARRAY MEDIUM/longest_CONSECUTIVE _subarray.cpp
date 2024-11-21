// Basically the question aims to find the longest sub arrays that too consecutive 
// eg. [ 101,1,4,3,105,2,106] now in this case we will have the longest sub-array as 
// [1,2,3,4] and its lnegth would be 4 and that is what we need to return 

// BRUTE FORCE APPROACH - we will be using basic linear search approacj in this case where
// we will check if we have x do we have x+1, x+2 and so on....it will closely be having a 
// timecomplexity of O(n^2) due to an external and internal loop
#include<iostream>
using namespace std;

longest = 1;
for( int i = 0; i<arr.size(); i++){
    x = arr[i]; //taking the first element to start longets subarray
    count = 1;  //even after taking one element our counter will have one elment 
    while( ls(arr,x+1) == true){  // linear searching if we have x+1, .. other terms 
        count++;
        x = x+1;
    }
}
bool ls(int arr[], int target){
    for( int i = 0; i<arr.size(); i++){
        if(arr[i] == target){
            return true;
        }else{
            return false;
        }
    }
}





// BETTER SOLUTION - it comprises of first we sort the array for eg. we have an array like
// [1,100,2,1,3,2,4,101,102,103,3] after sorting it would be somehat like
// [1,1,2,2,3,3,4,100,101,102,103] now we will star with count = 0, longest = 1,
// last_smallest = INT_MIN( last smallest will check did i already cove the same element
// before or its coming next in the consecutiev sequence )
HAVING A TIME CMPLEXITY OF ABOUT O(N)

int count  = 0;
int largest = 1;
int last_smallest = INT_MIN8;
sort(arr.begin(), arr.end());

for( int i = 0; i<arr.size(); i++){
    if(arr[i] - 1 == last_smallest){
        count++;
        last_smallest = arr[i];
    }else if{last_smallest != arr[i]}{
        count = 1;
        last_smallest = arr[i];
    }
    longest = max(largest,count);
  }
  return longest;
}


OPTIMAL SOLUTION - it will be using set data structure and we will be finding if 
the result exist in the set or not

int longest  = 1;
unordered_set<int> st;
for( int i =0; i<n; i++){
    st.insert(arr[i]);
}

for(auto it : st){
    if(st.find(it-1) == st.end()){
        int count++;
        int x = it;
        while(st.find(x+1) !=st.end()){
            x = x+1;
            coutn++;
        }
        longest = max(longes,count);
    }
    retunr longest;
}