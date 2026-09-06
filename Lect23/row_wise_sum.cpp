/*

LECTURE 23: ROW-WISE SUM


GOAL:
- Traverse a 2D array and calculate total sum of each 
  individual row.

APPROACH (Row-First Traversal):
- Use an outer loop 'i' for traversing rows and an inner loop 'j' 
  for traversing columns
- Initialize a 'sum' variable to 0 at start of every new row
- Add each element arr[i][j] to 'sum' and print final total 
  before outer loop moves to next row

COMPLEXITY:
- Time Complexity: O(R * C) where R is number of rows and C is columns.
- Space Complexity: O(1) auxiliary space.
 */

#include <iostream>
using namespace std;

// Function to calculate and print row-wise sum
void printRowSum(int arr[][3], int rows, int cols) {
    cout << "Printing Row-wise Sum:" << endl;
    for (int i = 0; i < rows; i++) {
        int sum = 0; // Reset sum for each new row
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        cout << "Sum of Row " << i << " = " << sum << endl;
    }
}

int main() {
    // Create a 2D array with 3 rows and 3 columns
    int arr[3][3];

    cout << "Enter elements for a 3x3 matrix (9 numbers total):" << endl;
    
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
    
    printRowSum(arr, 3, 3);

    return 0;
}

/*
OUTPUT:
Enter elements for a 3x3 matrix (9 numbers total):
3 4 11 2 12 1 7 8 7 

Your Matrix:
3 4 11 
2 12 1 
7 8 7 
Printing Row-wise Sum:
Sum of Row 0 = 18
Sum of Row 1 = 15
Sum of Row 2 = 22
*/