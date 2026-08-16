/*

        LECTURE 10: SORT 0, 1, AND 2 (Dutch National Flag)


GOAL:
- You are given an array consisting of only 0s, 1s, and 2s
- Sort the array in a single pass (O(N) time) with O(1) space

APPROACH 1: COUNTING (Brute Force / 2 Passes)
- Pass 1: Count how many 0s, 1s, and 2s exist in the array
- Pass 2: Overwrite the array. Put all 0s first, then 1s, then 2s
- Why it's not the best: It requires traversing the array twice

APPROACH 2: DUTCH NATIONAL FLAG ALGORITHM (Optimal)
- Use 3 Pointers: 'low' (starts at 0), 'mid' (starts at 0), 'high' (starts at n-1)
- 'mid' is our current explorer.
1. If arr[mid] == 0: We want 0s on the left. Swap arr[low] and arr[mid]. 
Move BOTH low++ and mid++.
2. If arr[mid] == 1: 1s belong in the middle. Just move mid++.
3. If arr[mid] == 2: We want 2s on the right. Swap arr[mid] and arr[high].
Move high--. (Do NOT move mid++, because the new element at mid needs checking).
 */

#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    // We keep exploring until our 'mid' pointer crosses the 'high' boundary
    while (mid <= high) {
        
        if (arr[mid] == 0) {
            // Swap with low boundary, increment both
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            // Already in the correct middle section, just move forward
            mid++;
        } 
        else if (arr[mid] == 2) {
            // Swap with high boundary, decrement high
            swap(arr[mid], arr[high]);
            high--;
            // Notice we do NOT do mid++ here
        }
    }
}

// Reusable function to print the array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Initialize an array with random 0s, 1s, and 2s
    vector<int> arr = {2, 0, 2, 1, 1, 0, 1, 2, 0};

    cout << "--- BEFORE SORTING ---" << endl;
    cout << "Array: ";
    printArray(arr);

    // Call the sorting function
    sort012(arr);

    cout << endl << "--- AFTER SORTING ---" << endl;
    cout << "Array: ";
    printArray(arr);

    return 0;
}

/*
OUTPUT:
--- BEFORE SORTING ---
Array: 2 0 2 1 1 0 1 2 0 

--- AFTER SORTING ---
Array: 0 0 0 1 1 1 2 2 2 
*/