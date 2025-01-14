// retirn the elements in form of a spiral for given matrix

#include<iostream>
using namespace std;
#include<vector>

vector<int> printSpiral(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int> ans;

    int top = 0;
    int bottom = n-1;
    int left = 0;
    int right = m-1;

    while (top <= bottom && left <= right) {


        for( int i = left; i<= right; i++){
            ans.push_back(mat[top][i]);
        }
        top++;

        for( int j = top; j<=bottom; j++){
            ans.push_back(mat[j][right]);
        }
        right--;

        if(top<=bottom){
            for(int k = right; k>=left; k--){
                ans.push_back(mat[bottom][k]);
            }
            bottom--;
        }

        if(left<=right){
            for(int l = bottom; l>=top; l--){
                ans.push_back(mat[l][left]);
            }
            left++;
        }
    }
    return ans;
}


int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat =  {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = printSpiral(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  
  return 0;
}