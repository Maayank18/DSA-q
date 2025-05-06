/*
-----------------------------------------------------
📝 Problem: Flood Fill Algorithm

🔍 Description:
Given a 2D image represented as a matrix of integers, where each integer represents the pixel color,
perform a "flood fill" starting from a given pixel (sr, sc). Change the color of all connected pixels
(connected 4-directionally — up, down, left, right) that have the same initial color to a new given color.

This is similar to the "paint bucket" tool in graphic editors.

📥 Input:
- image: 2D vector (matrix) representing the image
- sr: starting row index
- sc: starting column index
- newColor: the color with which to fill

📤 Output:
- A 2D vector representing the image after flood fill.

-----------------------------------------------------
📈 Time Complexity: O(N × M)
- N = number of rows, M = number of columns
- In the worst case, all pixels are visited once.

🧠 Space Complexity: O(N × M)
- For the visited/copy matrix + recursion stack space

-----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// DFS function to recursively fill connected cells with newColor
void dfs(int row, int col, vector<vector<int>>& ans,
         vector<vector<int>>& image, int newColor,
         int drow[], int dcol[], int initial_Color) {
    
    // Color the current cell
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    // Visit 4-directionally connected neighbors
    for (int i = 0; i < 4; i++) {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];

        // Check bounds, color match, and not already updated
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            image[newRow][newCol] == initial_Color &&
            ans[newRow][newCol] != newColor) {
            
            dfs(newRow, newCol, ans, image, newColor, drow, dcol, initial_Color);
        }
    }
}

// Main function to start flood fill
vector<vector<int>> FloodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int drow[] = {-1, 0, 1, 0}; // directions: up, right, down, left
    int dcol[] = {0, 1, 0, -1};

    int initial_Color = image[sr][sc];

    // If color is already the new color, nothing to do
    if (initial_Color == newColor)
        return image;

    vector<vector<int>> ans = image; // copy of image
    dfs(sr, sc, ans, image, newColor, drow, dcol, initial_Color); // perform DFS
    return ans;
}

// Utility function to print the image
void printImage(const vector<vector<int>>& image) {
    for (auto row : image) {
        for (auto pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

// Driver code
int main() {
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1; // starting row
    int sc = 1; // starting column
    int newColor = 2;

    cout << "Original Image:\n";
    printImage(image);

    vector<vector<int>> result = FloodFill(image, sr, sc, newColor);

    cout << "\nImage After Flood Fill:\n";
    printImage(result);

    return 0;
}
