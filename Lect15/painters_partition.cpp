/*

        LECTURE 15: PAINTER'S PARTITION PROBLEM


GOAL:
- Given an array representing lengths of N boards and K painters.
- Each painter takes 1 unit of time to paint 1 unit of board.
- A painter can only paint contiguous boards.
- Find minimum time required to paint all boards such that 
  maximum time taken by a painter is MINIMIZED.

APPROACH (Binary Search on Answer Space):
- This problem is identical in logic to Book Allocation Problem.
- search space for our answer ranges from 0 to sum of all boards[cite: 1].
- We set start = 0, end = sum of all boards.
- Calculate 'mid'. This represents proposed maximum time a painter is allowed to work.
- Run an 'isPossible' check:
    - Traverse array. If adding current board exceeds 'mid', 
      assign board to next painter.
    - If number of painters exceeds K, or a single board is larger 
      than 'mid', then this 'mid' is invalid (return false).
- If we successfully allocate all boards within 'mid' limit:
    - Store answer, but search left half (end = mid - 1) to find 
      an even smaller possible maximum time[cite: 1].
- If not possible, our time limit is too strict. Search right half (start = mid + 1)[cite: 1].
 */

#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if the proposed 'mid' time limit is valid
bool isPossible(vector<int>& boards, int n, int k, int mid) {
    int painterCount = 1;
    int boardSum = 0;

    for (int i = 0; i < n; i++) {
        // If adding the current board exceeds the 'mid' limit, assign to next painter
        if (boardSum + boards[i] <= mid) {
            boardSum += boards[i];
        } else {
            painterCount++;
            
            // If painters exceed K, or a single board is larger than 'mid'
            if (painterCount > k || boards[i] > mid) {
                return false;
            }
            // Assign the current board to the new painter
            boardSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int>& boards, int k) {
    int n = boards.size();
    int start = 0;
    int sum = 0;
    
    // Calculate the search space's upper bound (sum of all boards)
    for (int i = 0; i < n; i++) {
        sum += boards[i];
    }
    
    int end = sum;
    int ans = -1;

    // Apply Binary Search on the answer space
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(boards, n, k, mid)) {
            ans = mid;        // Store potential answer
            end = mid - 1;    // Try to minimize the maximum time by searching left
        } else {
            start = mid + 1;  // 'mid' is too small, search right
        }
    }
    
    return ans;
}

int main() {

    vector<int> boards = {5, 5, 5, 5};
    int k = 2; // Number of painters

    cout << "Boards Array: 5 5 5 5" << endl;
    cout << "Number of Painters: " << k << endl << endl;

    int result = findLargestMinDistance(boards, k);

    cout << "The minimum time required to get all boards painted is: " << result << endl;

    return 0;
}

/*
OUTPUT:
Boards Array: 5 5 5 5
Number of Painters: 2

The minimum time required to get all boards painted is: 10
*/