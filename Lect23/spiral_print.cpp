/*

 LECTURE 23: SPIRAL MATRIX (LEETCODE 54)


 THE GOAL:
 - Traverse an m x n matrix in spiral order and return all elements.

 THE APPROACH (Boundary Traversal):
 - Initialize 4 boundary pointers: startingRow, endingRow, 
   startingCol, and endingCol.
 - Maintain a 'count' variable to track how many elements have been 
   printed, stopping when count == total elements.
 - Perform 4 distinct traversals inside a while loop:
   1. Print Starting Row (Left to Right) -> startingRow++.
   2. Print Ending Column (Top to Bottom) -> endingCol--.
   3. Print Ending Row (Right to Left) -> endingRow--.
   4. Print Starting Column (Bottom to Top) -> startingCol++.

 COMPLEXITY:
 - Time Complexity: O(R * C) because we visit every element exactly once.
 - Space Complexity: O(R * C) for storing the elements in our answer vector.
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to return the spiral print of a 2D matrix
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    
    int row = matrix.size();
    int col = matrix[0].size();
    
    int count = 0;
    int total = row * col; // Total elements to print
    
    // Index initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;
    
    while (count < total) {
        // 1. Print Starting Row
        for (int index = startingCol; count < total && index <= endingCol; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++; // Squeeze top boundary downward
        
        // 2. Print Ending Column
        for (int index = startingRow; count < total && index <= endingRow; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--; // Squeeze right boundary inward
        
        // 3. Print Ending Row
        for (int index = endingCol; count < total && index >= startingCol; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--; // Squeeze bottom boundary upward
        
        // 4. Print Starting Column
        for (int index = endingRow; count < total && index >= startingRow; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++; // Squeeze left boundary inward
    }
    
    return ans;
}

// Helper function to print a 1D vector
void printVector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    // 3x4 Matrix
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Call the spiral print function
    vector<int> result = spiralOrder(matrix);

    cout << "\n--- RESULTS ---" << endl;
    cout << "Spiral Print Order: ";
    printVector(result);

    return 0;
}

/*
OUTPUT:
Original Matrix:
1 2 3 4 
5 6 7 8 
9 10 11 12 

--- RESULTS ---
Spiral Print Order: 1 2 3 4 8 12 11 10 9 5 6 7 
*/