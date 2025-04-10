/*
    PROBLEM STATEMENT:
    -------------------
    You are given two strings: beginWord and endWord, and a dictionary wordList.
    Return the length of the shortest transformation sequence from beginWord to endWord
    such that only one letter can be changed at a time and each transformed word must exist in the wordList.

    Example:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5 ("hit" -> "hot" -> "dot" -> "dog" -> "cog")

    TIME COMPLEXITY: O(M * 26 * N^2)
    - M = length of word
    - 26 = for a to z
    - N = number of words in list
    SPACE: O(N) - for visited tracking
*/

// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// bool isWordInList(string& word, vector<string>& wordList, vector<bool>& visited, int& index) {
//     for (int i = 0; i < wordList.size(); ++i) {
//         if (!visited[i] && wordList[i] == word) {
//             index = i;
//             return true;
//         }
//     }
//     return false;
// }

// int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//     int n = wordList.size();
//     vector<bool> visited(n, false); // Visited array

//     queue<pair<string, int>> q;
//     q.push({beginWord, 1});

//     while (!q.empty()) {
//         string current = q.front().first;
//         int steps = q.front().second;
//         q.pop();

//         // Try changing every character to a-z
//         for (int i = 0; i < current.size(); ++i) {
//             string temp = current;        // temp = hit 

//             for (char c = 'a'; c <= 'z'; ++c) {
//                 temp[i] = c;              // temp = ait

//                 int index = -1;
//                 if (isWordInList(temp, wordList, visited, index)) {  // ait,[],visited[false...],index
//                     if (temp == endWord) return steps + 1;

//                     visited[index] = true;
//                     q.push({temp, steps + 1});
//                 }
//             }
//         }
//     }

//     return 0;
// }

// int main() {
//     string beginWord = "hit";
//     string endWord = "cog";
//     vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

//     cout << "Shortest transformation length (no set): " << ladderLength(beginWord, endWord, wordList) << endl;

//     return 0;
// }




// OPTIMAL SOLUTION 


/*
    🔍 PROBLEM: Word Ladder (Leetcode 127)
    -------------------------------------
    Given two words - beginWord and endWord, and a wordList,
    find the shortest transformation sequence from beginWord to endWord such that:
    1. Only one letter can be changed at a time.
    2. Each transformed word must exist in the wordList.
    3. Return the number of steps in the shortest transformation sequence.

    🚀 EXAMPLE:
    Input: beginWord = "hit", endWord = "cog",
           wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5
    Explanation: hit → hot → dot → dog → cog

    ✅ APPROACH: Brute-force using BFS (Breadth First Search)
    - Start from the beginWord.
    - Try replacing each character (a-z) in the word and check if it exists in the wordList.
    - If yes, add it to the queue with steps + 1 and mark it visited by removing from set.
    - Continue until endWord is found.

    ⏱️ TIME COMPLEXITY:
    - O(N * M * 26) ≈ O(N * M) where:
      N = size of wordList
      M = length of each word (usually 3-10)
    - For each word in the queue, we try M positions and 26 letters each time.

    💾 SPACE COMPLEXITY:
    - O(N) for the set storing the wordList.
    - O(N) for the BFS queue in the worst case.
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Step 1: Initialize the queue for BFS with {word, steps}
    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    // Step 2: Convert wordList to a set for O(logN) lookup and remove beginWord
    set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord); // optional: it’s not in list usually

    // Step 3: Begin BFS
    while (!q.empty()) {
        string currentWord = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Step 4: If we found the endWord, return the steps
        if (currentWord == endWord) return steps;

        // Step 5: Try changing each character of the word
        for (int i = 0; i < currentWord.size(); i++) {
            string temp = currentWord;

            // Replace the i-th character with all a-z
            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;

                // If the new word is in the set (i.e., it's a valid next step)
                if (st.find(temp) != st.end()) {
                    q.push({temp, steps + 1});  // push into queue with incremented steps
                    st.erase(temp);             // remove from set to avoid revisiting
                }
            }
        }
    }

    // If endWord was never reached
    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << "Shortest transformation length: " << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}

