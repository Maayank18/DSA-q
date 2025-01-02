// this is another type of binary seach in which we basically be finding
// ( min distance between something ) is max  OR
// ( max distance between something ) is min

// so this question ask to find minimum distance between the cow is max such that
// we are able to able place all the cows given by user.

// Example = {0,3,4,7,9,10} are the stalls where cows can be placed
// cows = 4 = no. of cows to be placed
// finding max among ( minimum distance between the cows )

// one thing we can make out is distance will remain between 1, (max - min)
// afters sorting

// brute force approach - sorting and then applying and time complexity of O(max-min)xO(n)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int n)
{
    int maxx = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    return maxx;
}

int min(int arr[], int n)
{
    int minn = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minn)
        {
            minn = arr[i];
        }
    }
    return minn;
}

int cows_placed(int arr[], int n, int distance, int cows)
{
    int count_cows = 1;
    int last_cow = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last_cow >= distance)
        {
            count_cows++;
            last_cow = arr[i];
        }
    }
    if (count_cows >= cows)
        return true;
    else
        return false;
}

int finding(int arr[], int n, int cows)
{
    for (int distance = 1; distance <= max(arr, n) - min(arr, n); distance++)
    {
        if (cows_placed(arr, n, distance, cows) == true)
        {
            continue;
        }
        else
        {
            return distance - 1;
        }
    }
}

int main()
{
    int n;
    cout << " enter the number of stalls : ";
    cin >> n;

    int arr[n];
    cout << " the distances of the stalls are : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cows;
    cout << " enter the number of cows to be placed : ";
    cin >> cows;

    sort(arr, arr + n);

    int max_distance = finding(arr, n, cows);

    cout << " the maximum distance among the minimum distances is : " << max_distance << endl;

    return 0;
}

// FOR AN OPTIMISED APPROACH can we like just use binary search because again we have
// case where upto some point of time our answer is valid and after some time answer
// is invalid that is minimum distance goes ivalid after sometime and all cows
// cant be placed

// do check for the time complexity

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int cows_placed(int arr[], int n, int mid, int cows)
{
    int count_cows = 1;
    int last_cow = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last_cow >= mid)
        {
            count_cows++;
            last_cow = arr[i];
        }
    }
    if (count_cows >= cows)
        return true;
    else
        return false;
}

int finding(int arr[], int n, int cows)
{
    int low = 0;
    int high = arr[n - 1] - arr[0];
    int answer = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (cows_placed(arr, n, mid, cows) == true)
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return answer;
}
int main()
{
    int n;
    cout << " enter the number of stalls : ";
    cin >> n;

    int arr[n];
    cout << " the distances of the stalls are : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cows;
    cout << " enter the number of cows to be placed : ";
    cin >> cows;

    sort(arr, arr + n);

    int max_distance = finding(arr, n, cows);

    cout << " the maximum distance among the minimum distances is : " << max_distance << endl;

    return 0;
}