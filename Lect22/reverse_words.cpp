/*

        LECTURE 22: REVERSE WORDS IN A STRING


THE GOAL:
- Given a string containing multiple words separated by spaces,
  reverse each individual word in-place while keeping the overall 
  word order intact (e.g., "my name" -> "ym eman")

THE APPROACH (Space Delimiter & Two-Pointer):
- Iterate through the string character by character
- Use a 'start' pointer to keep track of the beginning of the current word
- When a space (' ') or the null character ('\0') is encountered, it 
  marks the exact end of that word
- Pass that specific substring (from 'start' to 'i - 1') to a standard 
  Two-Pointer reverse function
- Update 'start' to 'i + 1' to begin tracking the very next word

COMPLEXITY:
- Time Complexity: O(N) where N is the total length of the string, 
  as every character is visited and swapped a constant number of times
- Space Complexity: O(1) auxiliary space because all reversals 
  are done completely in-place
*/


#include <iostream>
#include <string>
#include <algorithm> // for standard swap

using namespace std;

// Helper function to reverse a specific portion of the string
void reverseSubstring(string &s, int start, int end) {
    while (start <= end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

// Main function to find words and reverse them
void reverseWords(string &s) {
    int start = 0;
    
    // Loop through the entire string, including the null character at the end
    for (int i = 0; i <= s.length(); i++) {
        // A space or null character marks the end of a word
        if (s[i] == ' ' || s[i] == '\0') {
            int end = i - 1;
            // Reverse the isolated word we just found
            reverseSubstring(s, start, end);
            // Move start to the first character of the NEXT word
            start = i + 1;
        }
    }
}

int main() {
    string phrase = "my name is pratik";
    
    cout << "Original String: " << phrase << endl;

    reverseWords(phrase);

    cout << "String with reversed words: " << phrase << endl;

    return 0;
}

/*
OUTPUT:
Original String: my name is pratik
String with reversed words: ym eman si kitarp
*/