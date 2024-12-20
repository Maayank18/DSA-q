//this is the basic problem that uses and brute force solution in we traverse the whole 
//array by making pointers and time complexity is o(N^2)

#include <iostream>
#include <utility> // For std::pair
using namespace std;

pair<int, int> twosum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return make_pair(i, j); // Return the indices as a pair
            }
        }
    }
    return make_pair(-1, -1); // Return -1, -1 if no solution is found
}

int main() {
    int arr[5] = {1, 2, 4, 6, 7}; // Array size corrected to 5
    int n = 5;
    int target = 11;
    pair<int, int> result = twosum(arr, n, target);

    if (result.first != -1) {
        cout << "Indices: " << result.first << ", " << result.second << endl;
    } else {
        cout << "No two numbers found that sum up to the target." << endl;
    }

    return 0;
}


// now if we talk about the better solution it can involve hashing approach in which
// we basically use hashmap to find the and sum pair and check if they really exist or 
// not and it has a time complxity of O(N) and also a space compelxity of O(N)


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

// the most optimal solution would again be involving the two pointer approach but 
// in a different form and having a time complexity of O(nlogn) for unsorted arrays and O(n)
// for sorted arrays and space complexity will be O(1)

#include<iostream>
using namespace std;

pair<int,int> find(int arr[], int n, int target){
    int left = 0;
    int right = n-1;
    while(left<right){
        if(arr[left]+arr[right]<target){
            left++;
        }else if (arr[left]+arr[right]>target)
        {
            right--;
        }else{
            return make_pair(left,right);
        }
        
    }
    return make_pair(-1,-1);
}
int main(){
    int arr[5] = {1,2,6,5,7};
    int n = 5;
    int target = 11;

    pair<int,int> result = find(arr,n,11);
    if (result.first != -1) {
        cout << "Indices: " << result.first << ", " << result.second << endl;
    } else {
        cout << "No pair found" << endl;
    }
    return 0;
}