/*

        LECTURE 21: CHECK IF ARRAY IS SORTED AND ROTATED (LEETCODE 1752)


GOAL:
- Determine if a given array was originally sorted in non-decreasing order and then 
rotated some number of positions

APPROACH (Drop Count):
- Traverse array and count how many times an element is strictly 
  greater than next element (nums[i-1] > nums[i])
- Because it is rotated, we also check circular boundary: nums[n-1] > nums[0]
- A valid sorted and rotated array will have AT MOST 1 drop
- If count of drops > 1, return false

COMPLEXITY:
- Time Complexity: O(N) because we traverse array exactly once
- Space Complexity: O(1) as we only use a single counter variable
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to check if array is sorted and rotated
bool check(vector<int>& nums) {
    int count = 0;
    int n = nums.size();

    // Traverse array to find any points where sorting breaks
    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            count++;
        }
    }

    // Check circular connection between last and first elements
    if (nums[n - 1] > nums[0]) {
        count++;
    }

    // If drop count is <= 1, it is a valid sorted & rotated array
    return count <= 1;
}

int main() {
    // Test Case 1: Valid sorted and rotated array
    vector<int> arr1 = {3, 4, 5, 1, 2};
    
    // Test Case 2: Array that is just sorted (also valid, rotated by 0)
    vector<int> arr2 = {1, 2, 3, 4, 5};
    
    // Test Case 3: Invalid array with too many drops
    vector<int> arr3 = {2, 1, 3, 4};

    cout << "Array 1 (3, 4, 5, 1, 2) is valid? " 
         << (check(arr1) ? "True" : "False") << endl;
         
    cout << "Array 2 (1, 2, 3, 4, 5) is valid? " 
         << (check(arr2) ? "True" : "False") << endl;
         
    cout << "Array 3 (2, 1, 3, 4) is valid? " 
         << (check(arr3) ? "True" : "False") << endl;

    return 0;
}

/*
OUTPUT:
Array 1 (3, 4, 5, 1, 2) is valid? True
Array 2 (1, 2, 3, 4, 5) is valid? True
Array 3 (2, 1, 3, 4) is valid? False
*/