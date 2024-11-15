// This basiaclly means the elements which have all elements small towards its right 
// eg.[10,22,12,3,0,6] the ouput answer will be [22,12,6]

// BRUTE FORCE 
// what we gonna do is running a loop and using a flag for finfind leaders and it will 
// almost be carrying a time cmplexity of O(n^2)
// in the worst case the space complexity will be O(N)

// for(int i = 0; i<n; i++){
//     bool leader = true;
//     for( int j = i+1; j<n; i++){
//         if(arr[j]>arr[i]){
//             leader = false;
//         }
//     }
//     if(leader == true ){
//         ans.push_back(arr[i])
//     }
// }

// It generally wont be having any better approach so directly going on to optimal one

// OPTIMAL APPROACH

vector<int> ans;
int maxi = INT_MIN;
int n = a.size();

for( int i =n-1; i>=0; i--){
    if(a[i]>maxi){
        ans.push_back(a[i]);
    }
    maxi = max(maxi,a[i]);
}

sort(ans.begin(),ans.end());
return ans;