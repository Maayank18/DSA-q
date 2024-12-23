//it is a brute force solution having a time cmplexity of nlog(n) + n
//also having a space complexity of O(n)

#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}


// it is the code which basiaclly forms a loop and has a time complexity 
// and space complexity O(n) and O(1) considering it to be most optimal 

#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n)
{
  int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) { // Check if the current element is unique
            i++;               // Move the unique element pointer
            arr[i] = arr[j];   // Place the unique element in its new position
        }
    }
    return i + 1; // Return the count of unique elements
}

int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}



