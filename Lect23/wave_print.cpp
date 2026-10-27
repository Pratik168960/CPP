/*

 LECTURE 23: PRINT LIKE A WAVE 


 THE GOAL:
 - Traverse a 2D array column by column, alternating the 
   vertical direction to form a wave pattern.

 THE APPROACH (Index Parity):
 - Run an outer loop 'j' to traverse every column from 0 to cols - 1.
 - Inside, check if the current column index 'j' is odd (j % 2 != 0).
 - If ODD: Traverse rows from Bottom-to-Top (rows - 1 down to 0).
 - If EVEN: Traverse rows from Top-to-Bottom (0 up to rows - 1).

 COMPLEXITY:
 - Time Complexity: O(R * C) because we visit every single element exactly once.
 - Space Complexity: O(R * C) to store the answer in a 1D vector (or O(1) 
   if we were only printing directly to the console).
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to return the wave print of a 2D matrix
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;
    
    // Outer loop traverses column by column
    for (int j = 0; j < mCols; j++) {
        
        // If the column index is ODD -> Bottom to Top
        if (j % 2 != 0) {
            for (int i = nRows - 1; i >= 0; i--) {
                ans.push_back(arr[i][j]);
            }
        } 
        // If the column index is EVEN -> Top to Bottom
        else {
            for (int i = 0; i < nRows; i++) {
                ans.push_back(arr[i][j]);
            }
        }
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
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Call the wave print function
    vector<int> result = wavePrint(arr, 3, 4);

    cout << "\n--- RESULTS ---" << endl;
    cout << "Wave Print Order: ";
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
Wave Print Order: 1 5 9 10 6 2 3 7 11 12 8 4 
*/