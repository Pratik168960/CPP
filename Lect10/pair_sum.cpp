/*

    LECTURE 10: PAIR SUM


GOAL:
- You are given an array of integers and a 'target' sum
- Find all unique pairs of elements in the array sum of it equals target
- The pairs should be returned with the smaller element first
- The final list of pairs should also be sorted

THE APPROACH (Nested Loops):
- We use two loops The outer loop picks the first element (arr[i])
- The inner loop checks all subsequent elements (arr[j] where j > i)
- If arr[i] + arr[j] == target, we found a valid pair
- We create a temporary vector to store the pair, ensuring we push the 
smaller number first using min(), and the larger number second using max()
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for min(), max(), and sort()
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    vector<vector<int>> ans;

    // Traverse the array for the first element of the pair
    for (int i = 0; i < arr.size(); i++) {
        
        // Traverse the rest of the array for the second element
        for (int j = i + 1; j < arr.size(); j++) {
            
            // Check if  target sum
            if (arr[i] + arr[j] == s) {
                vector<int> temp;
                
                // Always store the smaller element first 
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                
                // Add the pair to our answer list
                ans.push_back(temp);
            }
        }
    }

    // Sort the final list of pairs
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 5;

    cout << "Array elements: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Target Sum: " << target << endl;

    vector<vector<int>> result = pairSum(arr, target);

    if (result.empty()) {
        cout << "No pairs found" << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i][0] << " " << result[i][1] << endl;
        }
    }

    return 0;
}

/*
OUTPUT:
Array elements: 1 2 3 4 5 
Target Sum: 5
1 4
2 3
*/