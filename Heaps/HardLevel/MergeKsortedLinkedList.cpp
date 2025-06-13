// we are given arr containing different linked list 
//  our task is to join all the given linked list into one list in sorted order
// given that linked list which our given are already in sorted 


// METHOD 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Basic linked list node
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Comparator for min heap
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& lists) {
        priority_queue<Node*, vector<Node*>, compare> pq;

        for (auto list : lists) {
            if (list) pq.push(list);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!pq.empty()) {
            Node* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;

            if (top->next) pq.push(top->next);
        }

        return dummy->next;
    }
};

// Helper: Create linked list from vector
Node* createList(vector<int> vals) {
    if (vals.empty()) return NULL;
    Node* head = new Node(vals[0]);
    Node* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new Node(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> input = {
        {1, 2, 3},
        {4, 5},
        {5, 6},
        {7, 8}
    };

    vector<Node*> lists;
    for (auto& vec : input) {
        lists.push_back(createList(vec));
    }

    Solution sol;
    Node* merged = sol.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(merged);

    return 0;
}
