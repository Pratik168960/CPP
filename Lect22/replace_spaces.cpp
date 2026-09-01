/*

        LECTURE 22: REPLACE SPACES


GOAL:
- Given a string containing spaces, replace every single space 
  with a specific sequence of characters (e.g., "@40")

APPROACH (New String Allocation):
- Create an empty string called 'temp' to hold our final answer
- Iterate through original string character by character
- If current character is a space (' '), push '@', '4', and '0' 
  into 'temp' one by one
- If it is a normal character, simply push it directly into 'temp'

COMPLEXITY:
- Time Complexity: O(N) where N is length of string, as we 
  traverse it exactly once
- Space Complexity: O(N) because we allocate a brand new 'temp' string 
  to store modified result
*/


#include <iostream>
#include <string>

using namespace std;

// Function to replace all spaces with "@40"
string replaceSpaces(string s) {
    string temp = ""; // Initialize an empty string for result
    
    for (int i = 0; i < s.length(); i++) {
        // If we hit a space, append our special sequence
        if (s[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        } 
        // Otherwise, just append normal character
        else {
            temp.push_back(s[i]);
        }
    }
    
    return temp;
}

int main() {
    string phrase = "my name is pratik";
    
    cout << "Original String: " << phrase << endl;

    string result = replaceSpaces(phrase);

    cout << "String with replaced spaces: " << result << endl;

    return 0;
}

/*
OUTPUT:
Original String: my name is pratik
String with replaced spaces: my@40name@40is@40pratik
*/