/*

LECTURE 23: SEARCH A 2D MATRIX II (LEETCODE 240)


THE GOAL:
- Search for a target value in an m x n matrix where:
  1. Every row is sorted from left to right.
  2. Every column is sorted from top to bottom.

THE APPROACH (Top-Right Pivot):
- Start at the Top-Right corner (rowIndex = 0, colIndex = cols - 1).
- Compare the current element with the target:
  - If element == target: Return true.
  - If element < target: Target must be below, move down (rowIndex++).
  - If element > target: Target must be to the left, move left (colIndex--).

COMPLEXITY:
- Time Complexity: O(R + C) because at each step we eliminate a full row or column.
- Space Complexity: O(1) auxiliary space.
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to search in a Level-2 Sorted Matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Start from the Top-Right corner
    int rowIndex = 0;
    int colIndex = cols - 1;
    
    // Continue searching as long as we are inside the matrix boundaries
    while (rowIndex < rows && colIndex >= 0) {
        int element = matrix[rowIndex][colIndex];
        
        if (element == target) {
            return true; // Target found
        }
        
        if (element < target) {
            rowIndex++; // Eliminate current row, move down
        } else {
            colIndex--; // Eliminate current column, move left
        }
    }
    
    return false; // Target does not exist in the matrix
}

int main() {
    // 5x5 Matrix (Sorted rows and sorted columns)
    vector<vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    int target = 5;

    cout << "Level-2 Sorted Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nTarget to find: " << target << endl;

    // Call the search function
    cout << "\n--- RESULTS ---" << endl;
    if (searchMatrix(matrix, target)) {
        cout << "Element " << target << " is FOUND in the matrix!" << endl;
    } else {
        cout << "Element " << target << " is NOT FOUND." << endl;
    }

    return 0;
}

/*
OUTPUT:
Level-2 Sorted Matrix:
1	4	7	11	15	
2	5	8	12	19	
3	6	9	16	22	
10	13	14	17	24	
18	21	23	26	30	

Target to find: 5

--- RESULTS ---
Element 5 is FOUND in the matrix!
*/