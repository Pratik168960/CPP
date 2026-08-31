/*

        LECTURE 22: REVERSE A STRING


GOAL:
- Given a character array, reverse its contents in-place

APPROACH (Two-Pointer):
- First, calculate exact length of string (up to '\0')
- Initialize a 'start' pointer at 0 and an 'end' pointer at length - 1
- Swap characters at start and end
- Increment start (s++) and decrement end (e--) until start >= end

COMPLEXITY:
- Time Complexity: O(N) where N is length of string
- Space Complexity: O(1) because we swap elements in-place
*/


#include <iostream>
#include <algorithm> // Required for standard swap()

using namespace std;

// Function to find exact length of character array
int getLength(char name[]) {
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}

// Function to reverse character array
void reverseString(char name[], int n) {
    int s = 0;
    int e = n - 1;

    while (s < e) {
        swap(name[s++], name[e--]);
    }
}


int main() {
    char name[20];
    cout << "Enter your name: ";
    cin >> name;


    int len = getLength(name);
    reverseString(name, len);

    cout << "Reversed name is: " << name << endl;

    return 0;
}

/*
OUTPUT:
Enter your name: Pratik
Reversed name is: kitarP
*/