// the brute force solution contain a basic approach to find the solution where
//General case for SORTED ARRAYS ONLY 
// we can use a set data structure or map ds which would ensure that the following contains
//only unique elemenst and no duplicates are present 
//TC -> o(n1 logn)+O(n2 logn)+ O(n1+n2) and space complexity of O(n1+n2)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> unionA (vector<int> a, vector<int> b){
    vector<int> Union;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int b = 0;

    set<int> st;

    for(int i = 0; i<n1; i++){
        st.insert(a[i]);
    }
    for(int i = 0; i<n2; i++){
        st.insert(b[i]);
    }

    for( auto it : st){
        Union.push_back(it);
    }

    return Union;
}

int main() {
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};

    vector<int> unionResult = unionA(arr1, arr2);

    cout << "Union of the two sorted arrays: ";
    for (int elem : unionResult) {
        cout << elem << " ";
    }

    return 0;
}


// code sahi hai guess the error

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> GETunion(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    // Main loop to traverse both arrays
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    // Remaining elements in array `a`
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    // Remaining elements in array `b`
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}

int main()
{
    int n1;
    cout << "Enter size of array a: ";
    cin >> n1;

    int n2;
    cout << "Enter size of array b: ";
    cin >> n2;

    vector<int> a(n1), b(n2);

    cout << "Enter the elements of array a: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the elements of array b: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    vector<int> union_array = GETunion(a, b);

    cout << "The union of the arrays is: ";
    for (int i = 0; i < union_array.size(); i++)
    {
        cout << union_array[i] << " ";
    }

    return 0;
}
