/*

    LECTURE 10: TRIPLET SUM (LeetCode 15 / CodeStudio)


GOAL:
- You are given an array of integers and a 'target' sum
- Find all unique triplets their sum equals to target


APPROACH 1: BRUTE FORCE (Three Nested Loops)
Time Complexity: O(N^3) - Will cause Time Limit Exceeded (TLE)
for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
        for(int k=j+1; k<n; k++) {
            if(arr[i] + arr[j] + arr[k] == target) {
            // Found 
            }
        }
    }
}


APPROACH 2: OPTIMAL TWO-POINTER
Time Complexity: O(N^2)
1. Sort the array first
2. Fix the first element using a loop (pointer 'i')
3. Use two pointers ('left' = i + 1, and 'right' = n - 1) to find the remaining sum
4. If sum == target, store it
5. If sum < target, increment 'left' (we need a bigger number)
6. If sum > target, decrement 'right' (we need a smaller number)
7. Skip duplicates to ensure all triplets are unique
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int target) {
    vector<vector<int>> ans;
    
    // Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Fix the first element
    for (int i = 0; i < n; i++) {
        
        // Skip duplicate elements for 'i' to avoid duplicate triplets
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        // Two pointers for the remaining array
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == target) {
                // Match found
                ans.push_back({arr[i], arr[left], arr[right]});
                
                // Move both pointers inward
                left++;
                right--;

                // Skip duplicate elements for 'left'
                while (left < right && arr[left] == arr[left - 1]) {
                    left++;
                }
                // Skip duplicate elements for 'right'
                while (left < right && arr[right] == arr[right + 1]) {
                    right--;
                }
            } 
            else if (currentSum < target) {
                // We need a larger sum, move left pointer forward
                left++;
            } 
            else {
                // We need a smaller sum, move right pointer backward
                right--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {10, 5, 5, 5, 2};
    int target = 12;

    cout << "Original Array: ";
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl << "Target Sum: " << target << endl;

    vector<vector<int>> result = findTriplets(arr, arr.size(), target);

    if (result.empty()) {
        cout << "No triplets found" << endl;
    } else {
        cout << "Triplets that sum to " << target << ":" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    }

    return 0;
}

/*
OUTPUT:
Original Array: 10 5 5 5 2 
Target Sum: 12
Triplets that sum to 12:
2 5 5
*/