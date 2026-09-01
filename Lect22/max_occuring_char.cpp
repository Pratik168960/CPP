/*

        LECTURE 22: MAXIMUM OCCURRING CHARACTER


GOAL:
- Given a string, return character that appears most frequently
- If there is a tie, return character that is alphabetically smaller

APPROACH (Frequency Array):
- Create an integer array of size 26 initialized to 0 to act as buckets
- Iterate through string Convert each character to a 0-25 index 
  using (ch - 'a') for lowercase or (ch - 'A') for uppercase
- Increment value at that calculated index
- Iterate through 26-element array to find maximum value
- Convert winning index back to a character using (index + 'a')

COMPLEXITY:
- Time Complexity: O(N) to traverse string, plus O(1) to traverse 
  26-element array Overall time is O(N)
- Space Complexity: O(1) because our frequency array is strictly size 
  26, regardless of how massive input string gets
*/


#include <iostream>
#include <string>

using namespace std;

// Function to find highest frequency character
char getMaxOccuringChar(string s) {
    int arr[26] = {0}; // Buckets for 'a' to 'z'

    // Step 1: Create an array of counts of characters
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        int index = 0;
        
        if (ch >= 'a' && ch <= 'z') {
            index = ch - 'a'; // Convert lowercase letter to 0-25
        } else if (ch >= 'A' && ch <= 'Z') {
            index = ch - 'A'; // Convert uppercase letter to 0-25
        }
        
        arr[index]++; // Increment frequency at this index
    }

    // Step 2: Find maximum occurring character from frequency array
    int maxi = -1;
    int ans = 0;
    
    for (int i = 0; i < 26; i++) {
        if (maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }

    // Convert winning index back to its actual character
    return 'a' + ans;
}

int main() {
    string testStr = "test";
    
    cout << "Original String: " << testStr << endl;
    cout << "Maximum occurring character is: '" << getMaxOccuringChar(testStr) << "'" << endl;

    return 0;
}

/*
OUTPUT:
Original String: test
Maximum occurring character is: 't'
*/