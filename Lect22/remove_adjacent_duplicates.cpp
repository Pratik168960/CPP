/*

        LECTURE 22: REMOVE ADJACENT DUPLICATES (LEETCODE 1047)


GOAL:
- Repeatedly remove adjacent duplicate characters until 
  no adjacent duplicates remain (e.g., "abbaca" -> "ca").
- Master this specific pattern as it is heavily favored in 
  online screening tests for company placements

APPROACH (String as a Stack):
- Create an empty 'ans' string to build final result.
- Iterate through original string character by character.
- For each character, check if 'ans' is not empty AND if its 
  very last character matches current character.
- If they match, it is a duplicate! Remove last character 
  from 'ans' using .pop_back().
- If they do not match, add current character to 'ans' 
  using .push_back().

COMPLEXITY:
- Time Complexity: O(N) where N is length of string, 
  as we process each character exactly once.
- Space Complexity: O(N) for 'ans' string in worst-case 
  scenario where no duplicates exist.
*/


#include <iostream>
#include <string>

using namespace std;

// Function to remove adjacent duplicates
string removeDuplicates(string s) {
    string ans = "";
    
    for (int i = 0; i < s.length(); i++) {
        // Check if last character in ans matches current character
        // We use ans.back() to get last character easily
        if (ans.length() > 0 && ans.back() == s[i]) {
            ans.pop_back(); // Pop duplicate
        } else {
            ans.push_back(s[i]); // Push unique character
        }
    }
    
    return ans;
}

int main() {
    string s = "abbaca";
    
    cout << "Original String: " << s << endl;

    string result = removeDuplicates(s);

    cout << "String after removing adjacent duplicates: " << result << endl;

    return 0;
}

/*
OUTPUT:
Original String: abbaca
String after removing adjacent duplicates: ca
*/