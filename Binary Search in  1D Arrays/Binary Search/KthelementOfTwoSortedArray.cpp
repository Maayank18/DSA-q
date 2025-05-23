// BRUTE FORCE SOLUTION

#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k)
{
    vector<int> arr3;

    // apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            arr3.push_back(a[i++]);
        else
            arr3.push_back(b[j++]);
    }

    // copy the left-out elements:
    while (i < m)
        arr3.push_back(a[i++]);
    while (j < n)
        arr3.push_back(b[j++]);
    return arr3[k - 1];
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 5) << '\n';
}
