/*

LECTURE 23: COLUMN-WISE SUM


GOAL:
- Traverse a 2D array and calculate total sum of each 
  individual column

APPROACH (Column-First Traversal):
- Use an outer loop 'j' to track columns and an inner loop 'i' 
  to track rows
- Initialize a 'sum' variable to 0 at start of every new column
- Add arr[i][j] to sum and print final total before 
  outer loop moves to next column

COMPLEXITY:
- Time Complexity: O(R * C) where R is rows and C is columns.
- Space Complexity: O(1) auxiliary space.
 */

#include <iostream>
using namespace std;

// Function to calculate and print column-wise sum
void printColSum(int arr[][3], int rows, int cols) {
    cout << "Printing Column-wise Sum:" << endl;
    
    // Outer loop traverses columns
    for (int j = 0; j < cols; j++) {
        int sum = 0; 
        
        // Inner loop traverses rows for current column
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        cout << "Sum of Column " << j << " = " << sum << endl;
    }
}

int main() {
    // Create a 2D array with 3 rows and 3 columns
    int arr[3][3];

    cout << "Enter elements for a 3x3 matrix (12 numbers total):" << endl;
    
    // Taking input row-wise
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nYour Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    

    printColSum(arr, 3, 3);

    return 0;
}

/*
OUTPUT:
Enter elements for a 3x3 matrix (12 numbers total):
3 4 11 2 1 12 7 8 7 

Your Matrix:
3 4 11 
2 1 12 
7 8 7 
Printing Column-wise Sum:
Sum of Column 0 = 12
Sum of Column 1 = 13
Sum of Column 2 = 30
*/