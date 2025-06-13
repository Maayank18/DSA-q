// our aim is to check if the ith bit is set or not
// given a number in bianry form find whether the given 
// ith bit of that number is 1 or not
// if 1 it is set and 0 it is not set

// METHOD 1
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// bool isbitSet(string ans, int i){
//     int len = ans.size();

//     //  4 3 2 1 0 index 
//     //  1 0 1 1 1

//     if(ans[len-i-1] = '1'){
//         return true;
//     }else{
//         false;
//     }
// }

// bool checking(int num, int i){
//     string ans = "";

//     while( num > 0){
//         if(num % 2 == 1){
//             ans += '1';
//         }else{
//             ans += '0';
//         }
//         num /= 2;
//     }

//     reverse(ans.begin(),ans.end());

//     if(isbitSet(ans,i)){
//         return true;
//     }else{
//         return false;
//     }
// }

// int main(){
//     int num = 13;
//     int i = 2;
//     bool check = checking(num,i);
//     cout<<" is my bit set ? "<<check<<endl;
//     return 0;
// }





// METHOD 2 USING A SHIFTING OPERATOR 
// tc -> O(1)
// sc -> O(1)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 13;
    int i = 2;
    cout<<" is my bit set ? "<<(1 && (num>>i))<<endl;
    return 0;
}



// SIMILARLY WE CAN PRACTICE SETTING OF THE ITH BIT  -> TURN 0 -> 1
// SIMILARLY CLEARNG OF THE ITH BIT -> TURN 1 -> 0
// SIMILARLY TOGGLING THAT MEAN -> IF 1 -> 0, 0 -> 1