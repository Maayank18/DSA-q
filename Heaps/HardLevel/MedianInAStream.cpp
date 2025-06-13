// its a basic median findnig thing where we have to find the median of given 
// vector stream given that we could be aksed to find the mdeian at any given point

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MedianFinder {
    vector<int> stream;

public:
    void addNum(int num) {
        stream.push_back(num);
    }

    double findMedian() {
        sort(stream.begin(), stream.end()); // Brute force sort

        int n = stream.size();
        if (n % 2 == 1) {
            return stream[n / 2];
        } else {
            return (stream[n / 2 - 1] + stream[n / 2]) / 2.0;
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(5);
    mf.addNum(3);
    mf.addNum(2);

    cout << "Median: " << mf.findMedian() << endl;  // Output should be 2.5
    mf.addNum(4);
    cout << "Median: " << mf.findMedian() << endl;  // Output should be 3

    return 0;
}






// BETTER APPRAOCH 
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MedianFinder {
    priority_queue<int> left; // Max heap
    priority_queue<int, vector<int>, greater<int>> right; // Min heap

public:
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;
        else
            return left.top();
    }
};
