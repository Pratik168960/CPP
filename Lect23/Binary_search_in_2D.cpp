/*

LECTURE 23: SEARCH A 2D MATRIX (LEETCODE 74)


THE GOAL:
- Write an efficient algorithm that searches for a value in an m x n matrix.
- The matrix is strictly sorted (Left to Right, Top to Bottom).

THE APPROACH (Virtual 1D Binary Search):
- Treat the 2D matrix as a flat 1D array.
- Start = 0, End = (rows * cols) - 1.
- Calculate 'mid' and translate it to 2D coordinates using:
  row = mid / cols, col = mid % cols.
- Apply standard Binary Search logic: if element matches target, return true.
  If element < target, move right. Else, move left.

COMPLEXITY:
- Time Complexity: O(log(R * C)) where R is rows and C is columns.
- Space Complexity: O(1) auxiliary space.
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to perform Binary Search on a strictly sorted 2D Matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int start = 0;
    int end = rows * cols - 1; // Last index of the virtual 1D array
    
    int mid = start + (end - start) / 2;
    
    while (start <= end) {
        // Translate the 1D 'mid' index back into 2D matrix coordinates
        int element = matrix[mid / cols][mid % cols];
        
        if (element == target) {
            return true;
        }
        
        if (element < target) {
            start = mid + 1; // Move right
        } else {
            end = mid - 1; // Move left
        }
        
        mid = start + (end - start) / 2;
    }
    
    return false;
}

int main() {
    // 3x4 Strictly Sorted Matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 34;

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
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
Original Matrix:
1 3 5 7 
10 11 16 20 
23 30 34 60 

Target to find: 34

--- RESULTS ---
Element 34 is FOUND in the matrix!
*/