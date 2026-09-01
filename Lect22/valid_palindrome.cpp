/*

        LECTURE 22: VALID PALINDROME (LEETCODE 125)


THE GOAL:
- Check if a string is a palindrome, considering ONLY alphanumeric 
  characters and ignoring symbols/spaces
- The check must be case-insensitive

THE APPROACH (3-Step Process):
- Step 1: Remove all invalid characters by copying only letters 
  and numbers into a 'temp' string
- Step 2: Convert every character in the 'temp' string to lowercase
- Step 3: Run the standard Two-Pointer palindrome check on 'temp'

COMPLEXITY:
- Time Complexity: O(N) where N is the length of the string.
- Space Complexity: O(N) because we create a 'temp' string to hold valid characters
*/


#include <iostream>
#include <string>

using namespace std;

// Helper 1: Check if a character is alphanumeric (a-z, A-Z, 0-9)
bool valid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z') || 
        (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

// Helper 2: Convert an uppercase character to lowercase
char toLowerCase(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return ch;
    } else {
        return ch - 'A' + 'a';
    }
}

// Helper 3: Standard Two-Pointer Palindrome Check
bool checkPalindrome(string a) {
    int s = 0;
    int e = a.length() - 1;

    while (s <= e) {
        if (a[s] != a[e]) {
            return false;
        } else {
            s++;
            e--;
        }
    }
    return true;
}

// Main Function connecting all 3 steps
bool isPalindrome(string s) {
    // Step 1: Remove invalid characters
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        if (valid(s[i])) {
            temp.push_back(s[i]);
        }
    }

    // Step 2: Convert to lowercase
    for (int i = 0; i < temp.length(); i++) {
        temp[i] = toLowerCase(temp[i]);
    }

    // Step 3: Check palindrome
    return checkPalindrome(temp);
}

int main() {
    string phrase = "A man, a plan, a canal: Panama";
    
    cout << "Original Phrase: " << phrase << endl;

    if (isPalindrome(phrase)) {
        cout << "It is a valid palindrome!" << endl;
    } else {
        cout << "It is NOT a valid palindrome!" << endl;
    }

    return 0;
}

/*
EXPECTED CONSOLE OUTPUT:
Original Phrase: A man, a plan, a canal: Panama
It is a valid palindrome!
*/