/*

        LECTURE 22: PERMUTATION IN STRING (LEETCODE 567)


GOAL:
- Given two strings s1 and s2, return true if s2 contains a 
  permutation of s1, or false otherwise
- In other words, one of first string's permutations is 
  substring of second string.

APPROACH (Sliding Window & Frequency Arrays):
- Create a frequency array (count1) of size 26 for string s1
- Create a 'window' of exact same size as s1 to slide across s2
- Process very first window in s2 and store its frequencies in count2
- Compare count1 and count2. If they match, we found a permutation!
- If not, slide window forward by exactly 1 character:
    1. Add new character (entering window) to count2
    2. Remove old character (leaving window) from count2
- Compare again. Repeat until end of s2

COMPLEXITY:
- Time Complexity: O(N + M) where N and M are lengths of s1 and s2, 
  because we process each character at most twice.
- Space Complexity: O(1) because our count arrays are strictly size 26.
*/


#include <iostream>
#include <string>

using namespace std;

// Helper function to compare two frequency arrays of size 26
bool checkEqual(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    // Edge case: if s1 is larger than s2, it can't be a substring
    if (s1.length() > s2.length()) {
        return false;
    }

    // Step 1: Create character count array for s1
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++) {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // Step 2: Traverse s2 in a window of size s1.length()
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    // Process first window
    while (i < windowSize && i < s2.length()) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // Check if first window is a match
    if (checkEqual(count1, count2)) {
        return true;
    }

    // Step 3: Process rest of windows (Sliding window)
    while (i < s2.length()) {
        // Add new character entering window
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        // Remove old character leaving window
        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;

        // Move window forward
        i++;

        // Check for match again
        if (checkEqual(count1, count2)) {
            return true;
        }
    }

    return false;
}

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    
    cout << "String 1 (Target): " << s1 << endl;
    cout << "String 2 (Search Space): " << s2 << endl;


    if (checkInclusion(s1, s2)) {
        cout << "True! A permutation of '" << s1 << "' exists in '" << s2 << "'." << endl;
    } else {
        cout << "False! No permutation found." << endl;
    }

    return 0;
}

/*
OUTPUT:
String 1 (Target): ab
String 2 (Search Space): eidbaooo
True! A permutation of 'ab' exists in 'eidbaooo'.
*/