// code sahi hai guess the error

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> GETunion(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
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
        while (i < n1)
        {
            if (unionArr.size() == 0 || unionArr.back() != a[j]){
                unionArr.push_back(a[i]);
                i++;
            }
        }

        while (j < n2)
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
                j++;
            }
        }
    }
    return unionArr;
}
    int main()
    {
        int n1;
        cout<<" enter size of array a : ";
        cin>>n1;
        int n2;
        cout<<" enter size of array b : ";
        cin>>n2;
        vector<int> a(n1);
        vector<int> b(n2);
        cout << " enter the elements of array a : ";
        for (int i = 0; i < a.size(); i++)
        {
            cin >> a[i];
        }

        cout << " the array a entered by user : ";
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << " enter the elements of array b :";
        for (int i = 0; i < b.size(); i++)
        {
            cin >> b[i];
        }

        cout << " the array a entered by user : ";
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;

        vector<int> union_array = GETunion(a, b);
        cout << " The union arrays is : ";
        for (int i = 0; i < union_array.size(); i++)
        {
            cout << union_array[i] << " ";
        }
        return 0;
    }