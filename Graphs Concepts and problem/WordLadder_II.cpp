/*
Problem Statement:
------------------
Given two words, beginWord and endWord, and a wordList, find all the shortest transformation sequences 
from beginWord to endWord such that:

1. Only one letter can be changed at a time.
2. Each transformed word must exist in the wordList.
3. Return all shortest transformation sequences in any order.

Example:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"], ["hit","hot","lot","log","cog"]]

---------------------------------------------------------
Time Complexity:
- O(N * 26 * L), where:
    N = number of words in wordList
    L = length of each word
- In the worst case, each word generates up to 26 * L new transformations.

Space Complexity:
- O(N * L) for queue and storing intermediate paths.
- O(K) for storing final answer, where K = number of valid shortest sequences.
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList) {
    // Create a set for fast lookup of words
    unordered_set<string> st(wordList.begin(), wordList.end());

    // Queue to perform BFS — it stores paths, not just words
    queue<vector<string>> q;
    q.push({beginWord});  // Start with the beginWord path

    // Used to keep track of words used at the current BFS level
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);

    int level = 0;  // Track the current BFS level
    vector<vector<string>> ans;  // Store the final sequences (answers)

    while (!q.empty()) {
        // Get the current path (sequence of words)
        vector<string> vec = q.front();
        q.pop();

        // If the path has increased in length, we are at a new level
        if (vec.size() > level) {
            level++;  // Move to the next level in BFS

            // Remove all the words used in the previous level from the set
            for (auto word : usedOnLevel) {
                st.erase(word);
            }
            usedOnLevel.clear();  // Reset for the new level
        }

        // Get the last word from the current path
        string word = vec.back();

        // If we've reached the endWord
        if (word == endWord) {
            // Only add if it's the first path or same length as shortest found so far
            if (ans.size() == 0 || vec.size() == ans[0].size()) {
                ans.push_back(vec);
            }
            continue;  // Skip further exploration after reaching endWord
        }

        // Try changing each character of the word to all letters from a-z
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];  // Save original character

            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // If the new word exists in the set (valid transformation)
                if (st.count(word) > 0) {
                    // Add the new word to the path
                    vec.push_back(word);

                    // Enqueue this new path for further exploration
                    q.push(vec);

                    // Mark the word as used on this level
                    usedOnLevel.push_back(word);

                    // Backtrack: remove the last word to try other options
                    vec.pop_back();
                }
            }

            // Restore original word before next character change
            word[i] = original;
        }
    }

    return ans;  // Return all shortest transformation sequences
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> result = findSequences(beginWord, endWord, wordList);

    cout << "All shortest transformation sequences:\n";
    for (auto sequence : result) {
        for (auto word : sequence) {
            cout << word << " ";
        }
        cout << "\n";
    }

    return 0;
}
