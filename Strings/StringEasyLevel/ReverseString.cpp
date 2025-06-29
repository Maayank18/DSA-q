// Our basic aim to find the reverse of the given string 



// BRTUTE FORCE APPROACH 
// TC -> O(n)
// sc -> O(n)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string fun(string str){
    string temp = str;
    int n = str.length();

    for(int i = 0; i<n; i++){
        temp[n-i-1] = str[i];
    }

    return temp;
}

int main(){
    string str = "mayank";
    string reversed = fun(str);

    cout<<" the reverse of "<<str<<" is "<<reversed<<endl;
    return 0;
}





// BETTER APPROACH
// tc -> O(n)
// sc -> O(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string f(string &str){
    int n = str.length();
    int start = 0;
    int end = n-1;

    while(start <= end){
        swap(str[start],str[end]);
        start++;
        end--;
    }

    return str;

}

int main(){
    string str = "mayank";
    string reversed = f(str);

    cout<<" the reverse of "<<str<<" is "<<reversed<<endl;
    return 0;
}







// ANOTHER WAY OF DOING CAN BE 
// TC -> O(n)
// SC -> O(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "mayank";
    reverse(str.begin(),str.end());

    cout<<" the reverse is "<<str<<endl;
    return 0;
}