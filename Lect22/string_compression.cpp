/*

        LECTURE 22: STRING COMPRESSION (LEETCODE 443)


GOAL:
- Compress an array of characters in-place.
- For groups of consecutive repeating characters:
  - If length is 1, just append character.
  - If length > 1, append character followed by its count.
- If count is 10 or more, split it into multiple characters (e.g., '1', '2').
- Return new length of compressed array.

APPROACH (Two-Pointer Read/Write):
- Use an 'i' pointer to read through array and find consecutive groups.
- Use an 'ansIndex' pointer to track exactly where to write compressed data.
- Run a nested loop to push 'j' forward as long as characters match.
- Write character at 'ansIndex'.
- Calculate count (j - i). If count > 1, convert it to a string and 
  write its individual digits into array.
- Jump 'i' forward to 'j' to process next distinct character group.

COMPLEXITY:
- Time Complexity: O(N) because we iterate through characters exactly once.
- Space Complexity: O(1) auxiliary space as all modifications are in-place.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compress character array
int compress(vector<char>& chars) {
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while (i < n) {
        int j = i + 1;
        
        // Move j forward as long as characters match
        while (j < n && chars[i] == chars[j]) {
            j++;
        }

        // Store old character at write pointer
        chars[ansIndex++] = chars[i];

        int count = j - i;

        // If count > 1, convert to string and store individual digits
        if (count > 1) {
            string cnt = to_string(count);
            for (char ch : cnt) {
                chars[ansIndex++] = ch;
            }
        }

        // Move read pointer to start of next character group
        i = j;
    }

    return ansIndex;
}

// Helper function to print only up to new compressed length
void printVector(const vector<char>& v, int length) {
    for (int i = 0; i < length; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    vector<char> chars = {'a', 'a', 'b', 'c', 'c', 'c'};
    
    cout << "Original Array: ";
    printVector(chars, chars.size());


    int newLen = compress(chars);

    cout << "New Length: " << newLen << endl;
    cout << "Compressed Array: ";
    printVector(chars, newLen);

    return 0;
}

/*
OUTPUT:
Original Array: a a b c c c 
New Length: 5
Compressed Array: a 2 b c 3 
*/