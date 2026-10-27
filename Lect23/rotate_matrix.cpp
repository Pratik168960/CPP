/*

LECTURE 23: ROTATE IMAGE BY 90 DEGREES (LEETCODE 48)


THE GOAL:
- Rotate an n x n 2D matrix by 90 degrees clockwise.
- The operation must be done strictly in-place (O(1) extra space).

THE APPROACH (Transpose + Reverse):
- Step 1 (Transpose): Iterate through the matrix and swap matrix[i][j] 
  with matrix[j][i]. To avoid double-swapping, the inner loop 'j' 
  should strictly start from 'i'.
- Step 2 (Reverse): Iterate through each row of the transposed matrix 
  and reverse its elements.

COMPLEXITY:
- Time Complexity: O(N^2) where N is the number of rows/cols.
- Space Complexity: O(1) as we modify the original matrix.
 */

#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

// Function to rotate the matrix by 90 degrees
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Helper function to print a 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 3x3 Matrix Example[cite: 4]
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // Call the rotate function
    rotate(matrix);

    cout << "\n--- RESULTS ---" << endl;
    cout << "Matrix rotated by 90 degrees:" << endl;
    printMatrix(matrix);

    return 0;
}

/*
OUTPUT:
Original Matrix:
1 2 3 
4 5 6 
7 8 9 

--- RESULTS ---
Matrix rotated by 90 degrees:
7 4 1 
8 5 2 
9 6 3 
*/