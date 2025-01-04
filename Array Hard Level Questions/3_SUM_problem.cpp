// just like 2 sum problem this problem is almost same but the only difference come when
// 1. should not have duplicate elements.
// 2. should not repeat any existing triplet
// 3. i != j!= k


// BRUTE FORCE SOLUTION -> somewhere we can think of iteration in form of nested loop
// TC  -> O(n^3) and to store and confirm unique element we can use set data structure

// #include<iostream>
// #include<bits/stdc++.h>
// #include<vector>
// #include<set>
// using namespace std;

// vector<vector<int>> sum_3(vector<int> arr){
//     int size = arr.size();
//     set<vector<int>> st;

//     for(int i = 0; i<size; i++){
//         for(int j = i+1; j<size; j++){
//             for(int k = j+1; k<size; k++){
//                 if( arr[i] + arr[j] + arr[k] == 0){
//                    vector<int> temp = { arr[i], arr[j], arr[k]};
//                    sort(temp.begin(),temp.end());
//                    st.insert(temp);
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

// int main(){
//     int n;
//     cout<<" enter the size of vector array : ";
//     cin>>n;

//     vector<int> arr(n);
//     cout<<" enter the elements of array : ";
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }

//     vector<vector<int>> result = sum_3(arr);

//     for (int i = 0; i < result.size(); i++) {
//         for (int j = 0; j < result[i].size(); j++) {
//             cout << result[i][j] << " ";  // Print each element in the row
//         }
//         cout << endl;  // Move to the next row
//     }
//     return 0;
// }


// BTTER SOLUTION WILL DEFINITELY BE USING A O(n^2) and how is tha possible 
// by using a hashmap data structure

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> sum_3(vector<int> arr){
    set<vector<int>> st;
    for(int i = 0; i<arr.size(); i++){
        set<int> hashset;
        for(int j =i+1; j<arr.size(); j++){
            int third_Value = -(arr[i] + arr[j]);
            if(hashset.find(third_Value) != hashset.end()){
                vector<int> temp = { arr[i], arr[j], third_Value};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    int n;
    cout<<" enter the size of vector array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<" enter the elements of array : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    vector<vector<int>> result = sum_3(arr);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";  // Print each element in the row
        }
        cout << endl;  // Move to the next row
    }
    return 0;
}


// MOST OPTIMAL SOLUTION ISOMEWHAT A POINTER APPROACH 
// in which we gonna fix the i pointer and make j and k movable 
// we will first sort our array and then proceed

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> sum_3(vector<int> arr){
    vector<vector<int>> ans;
    for(int i = 0; i<arr.size(); i++){
        if( i> 0 && arr[i] == arr[i-1]) continue;

        int j = i+1;
        int k = arr.size()-1;

        while( j<k ){
            int sum = arr[i] + arr[j] + arr[k];
            if( sum < 0){
                j++;
            }else if( sum > 0){
                k--;
            }else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while( j<k && arr[j] == arr[j-1]) j++;
                while( j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }
   return ans;
}

int main(){
    int n;
    cout<<" enter the size of vector array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<" enter the elements of array : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    vector<vector<int>> result = sum_3(arr);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";  // Print each element in the row
        }
        cout << endl;  // Move to the next row
    }
    return 0;
}

