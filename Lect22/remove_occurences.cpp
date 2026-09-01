/*

LECTURE 22: REMOVE ALL OCCURRENCES OF A SUBSTRING


THE GOAL:
- Given a string 's' and a substring 'part', remove all 
  occurrences of 'part' from 's' until it no longer exists

THE APPROACH (STL Functions):
- Use a while loop that continues as long as two conditions are met:
  1. The string 's' is not empty (s.length() != 0).
  2. The 'part' is actually found inside 's' (s.find(part) < s.length())
- Inside the loop, use s.erase() starting from the found index, 
  spanning the exact length of 'part'

COMPLEXITY:
- Time Complexity: O(N * M) where N is the length of 's' and M is 
  the length of 'part', because find() and erase() shift elements.
- Space Complexity: O(1) auxiliary space as we modify the string in-place.
*/

#include <iostream>
#include <string>

using namespace std;

string removeOccurrences(string s, string part) {
    // Loop while the string is not empty and the part is still found inside it
    while (s.length() != 0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    
    cout << "Original String: " << s << endl;
    cout << "Substring to remove: " << part << endl;

    string result = removeOccurrences(s, part);

    cout << "String after removals: " << result << endl;

    return 0;
}

/*
OUTPUT:
Original String: daabcbaabcbc
Substring to remove: abc
String after removals: dab
*/