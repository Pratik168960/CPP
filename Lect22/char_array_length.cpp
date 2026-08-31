/*

        LECTURE 22: CHAR ARRAYS & LENGTH OF STRING


GOAL:
- Understand how to initialize and take input for a Character Array
- Write a custom function to calculate exact length of stored word

APPROACH:
- Character arrays are automatically terminated by a Null Character ('\0')
- To find length, we do not need to know array's total capacity
- We simply run a loop starting from index 0 and increment a counter 
  until we encounter '\0' character

COMPLEXITY:
- Time Complexity: O(N) where N is number of characters in string
- Space Complexity: O(1) as we only use a single counter variable
*/


#include <iostream>
using namespace std;

// Function to find exact length of character array
int getLength(char name[]) {
    int count = 0;
    
    // Loop continues as long as current character is NOT null character
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    
    return count;
}


int main() {
    // Initialize a character array with a maximum capacity of 20 characters
    char name[20];

    cout << "Enter your name: ";
    // Taking input. Note: cin will stop reading if you enter a space!
    cin >> name;



    cout << "Your name is: " << name << endl;
    cout << "Length of your name is: " << getLength(name) << endl;

    return 0;
}

/*
OUTPUT:
Enter your name: Pratik
Your name is: Pratik
Length of your name is: 6
*/