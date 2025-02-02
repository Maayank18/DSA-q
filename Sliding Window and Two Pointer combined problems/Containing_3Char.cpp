

// BRUTE FORCE SOLUTION WHERE WE USE LOOPS FOR GENERATING ALL THE SUBARRAYS 
// AND KEEP A COUNT
// TIME COMPLEXITY -> O(N^2)
// SPACE COMPLEXITY -> O(3)
#include<iostream>
#include<string>
using namespace std;

int countSubArray( string s){
    int n = s.size();
    int counter = 0;
    for(int i = 0; i<n; i++){
        int hash[3] = {0};
        for(int j = i; j<n; j++){
            hash[s[j]-'a'] = 1;
            if(hash[0]+hash[1]+hash[2]>=3){
                counter++;
            }
        }
    }
    return counter;
}

int main(){
    string s = "bbacba";
    int counting = countSubArray(s);
    cout<<" sub arrays containg all three chaarcters are : "<<counting<<endl;
    return 0;
}