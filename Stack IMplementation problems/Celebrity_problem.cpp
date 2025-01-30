// aonly thing to remember is 
// IF YOU ARE CELEBRITY YOU WOULD KNOW 0 PEOPLE
// AND EVERYONE EXCEPT THE CELEBRITY KNOWS HIMSELF
// KnowMePeople = n-1
// IknowPeople = 0


#include<iostream>
#include<vector>
using namespace std;

int WhoIsCelebrity(vector<vector<int>> arr, int n){
    vector<int> KnowsMe(n);
    vector<int> iKnow(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i!=j && arr[i][j] == 1){
                KnowsMe[j]++;
                iKnow[i]++;
            }
        }
    }

    for( int i = 0; i<n; i++){
        if(KnowsMe[i] == n-1 && iKnow[i] == 0 ){
            return i;
        }
    }
    return -1;
}

    int main() {
    vector<vector<int>> M = {{0, 1, 1, 1},
                              {0, 0, 0, 1},
                              {0, 0, 0, 1},
                              {0, 0, 0, 0}};
    int n = M.size();
    cout << "Celebrity: " << WhoIsCelebrity(M, n) << endl;
    return 0;
}
