/*

        LECTURE 15: AGGRESSIVE COWS


GOAL:
- You are given an array representing positions of stalls
- You have K aggressive cows that you need to place in these stalls
- Place cows such that minimum distance between any two cows 
  is as LARGE as possible (Largest Minimum Distance)

APPROACH (Binary Search on Answer Space):
- First, SORT array of stalls This is crucial to place cows sequentially.
- search space for distance ranges from 0 to maximum possible distance.
- We set start = 0, and end = maximum distance (arr[n-1] - arr[0])
- Calculate 'mid', which represents a proposed minimum distance between cows.
- Run an 'isPossible' check to see if we can place all K cows with at least 'mid' distance:
    - Place first cow in first stall.
    - Iterate through remaining stalls. If distance from last placed cow 
      is >= mid, place next cow and update last placed position.
    - If all K cows are placed, return true.
- If it is possible, store answer. Because we want LARGEST distance, 
  move RIGHT (start = mid + 1) to check if a larger gap is also valid
- If not possible, proposed gap is too wide. Move LEFT (end = mid - 1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if the proposed 'mid' distance is valid
bool isPossible(vector<int>& stalls, int k, int mid) {
    int cowCount = 1; // Place the first cow
    int lastPos = stalls[0]; // Position of the first cow

    for (int i = 0; i < stalls.size(); i++) {
        // Check if the gap between the current stall and the last placed cow is enough
        if (stalls[i] - lastPos >= mid) {
            cowCount++;
            
            // If all cows have been successfully placed, it's a valid distance
            if (cowCount == k) {
                return true;
            }
            // Update the last position to the current stall
            lastPos = stalls[i];
        }
    }
    return false; // Couldn't place all K cows with 'mid' distance
}

int aggressiveCows(vector<int>& stalls, int k) {
    // Step 1: Sort the stalls
    sort(stalls.begin(), stalls.end());
    
    int start = 0;
    int n = stalls.size();
    
    // Step 2: Set the max possible distance (Search space upper bound)
    int end = stalls[n - 1] - stalls[0];
    int ans = -1;

    // Step 3: Binary Search on the answer space
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(stalls, k, mid)) {
            ans = mid;        // Store potential answer
            start = mid + 1;  // Try to maximize the distance by searching right
        } else {
            end = mid - 1;    // 'mid' distance is too large, search left
        }
    }
    
    return ans;
}

int main() {

    vector<int> stalls = {4, 2, 1, 3, 6};
    int k = 2; // Number of cows

    cout << "Original Stalls: 4 2 1 3 6" << endl;
    cout << "Number of Cows: " << k << endl << endl;

    int result = aggressiveCows(stalls, k);

    cout << "The largest possible minimum distance is: " << result << endl;

    return 0;
}

/*
OUTPUT:
Original Stalls: 4 2 1 3 6
Number of Cows: 2

The largest possible minimum distance is: 5
*/