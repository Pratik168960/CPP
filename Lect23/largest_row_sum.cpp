/*

        LECTURE 23: LARGEST ROW SUM


GOAL:
- Identify row with maximum sum and return its index

APPROACH (Tracking Max):
- Track maximum sum using 'maxi' (initialized to INT_MIN)
- Track winning row index using 'rowIndex'
- Iterate row-wise. If 'sum > maxi', update both variables

COMPLEXITY:
- Time Complexity: O(R * C) where R is rows and C is columns
- Space Complexity: O(1) auxiliary space
*/


#include <iostream>
#include <climits> // Required for INT_MIN

using namespace std;

// Function to find largest row sum
int largestRowSum(int arr[][3], int rows, int cols) {
    int maxi = INT_MIN; // Track max sum
    int rowIndex = -1;  // Track winning row

    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }

        // Update if a new highest sum is found
        if (sum > maxi) {
            maxi = sum;
            rowIndex = i;
        }
    }

    cout << "Maximum sum is " << maxi << endl;
    return rowIndex;
}

int main() {
    int arr[3][3];

    cout << "Enter elements for a 3x3 matrix (9 numbers total):" << endl;
    
    // Taking input row-wise
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Your Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    

    // Call function and capture returned index
    int ansIndex = largestRowSum(arr, 3, 4);
    cout << "Row at index " << ansIndex << " has largest sum." << endl;

    return 0;
}

/*
OUTPUT:
Your Matrix:
3 4 11 0 
2 1 12 0 
1 7 8 6 

--- RESULTS ---
Maximum sum is 22
Row at index 2 has largest sum.
*/