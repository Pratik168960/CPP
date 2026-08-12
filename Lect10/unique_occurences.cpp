/*

    LECTURE 10: UNIQUE NUMBER OF OCCURRENCES (LeetCode 1207)


GOAL:
- Given array of integers determine if the frequency of each element is unique
- Example: [1, 2, 2, 1, 1, 3] -> 1 (freq:3), 2 (freq:2), 3 (freq:1) -> TRUE

OPTIMAL APPROACH (Using Frequency Array & Sorting):
- Since LeetCode constraints usually say numbers are between -1000 and 1000,
we can use a counting array of size 2001 
- We add 1000 to each number so negative numbers become positive indexes 
(e.g., -1000 becomes index 0, 0 becomes index 1000)
- After counting how many times each number appears we sort the counts
- Finally, we check if any two adjacent non-zero counts are exactly the same
*/

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    // Step 1: Create an array to store frequencies and initialize with 0
    vector<int> count(2001, 0);
    
    // Step 2: Count the occurrences of each element
    for (int i = 0; i < arr.size(); i++) {
        // Shift by +1000 to handle negative numbers in the array
        count[arr[i] + 1000]++; 
    }
    
    // Step 3: Sort the frequency array to easily find duplicates
    sort(count.begin(), count.end());
    
    // Step 4: Check for matching adjacent frequencies
    for (int i = 1; i < 2001; i++) {
        // If the frequency is greater than 0 and equals the previous frequency
        if (count[i] != 0 && count[i] == count[i - 1]) {
            return false; // Found duplicate occurrences!
        }
    }
    
    return true; // All occurrences were perfectly unique
}

int main() {
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    
    vector<int> arr2 = {1, 2};
    
    vector<int> arr3 = {-3, -1, -1, -3, -3, 10};

    cout << uniqueOccurrences(arr1) << endl;
    cout << uniqueOccurrences(arr2) << endl;
    cout << uniqueOccurrences(arr3) << endl;

    return 0;
}

/*
OUTPUT:
1
0
1
*/