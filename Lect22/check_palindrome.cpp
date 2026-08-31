/*

        LECTURE 22: CHECK IF STRING IS A PALINDROME


GOAL:
- Given a character array, determine whr it is a palindrome
- Handle case-insensitivity so that 'A' matches 'a'

APPROACH (Two-Pointer):
- Find length of character array using null character ('\0')
- Place 's' at index 0 and 'e' at index length - 1
- Convert characters to lowercase before comparing
- If a[s] != a[e], return false immediately
- Increment s and decrement e until s > e
- If no mismatch is found, return true

COMPLEXITY:
- Time Complexity: O(N) where N is length of string
- Space Complexity: O(1) auxiliary space
*/

#include <iostream>

using namespace std;

// Helper function to convert uppercase characters to lowercase
char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;          
    }
    else
    {
        return ch - 'A' + 'a';          
    }
}

// Function to calculate the string length
int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;            
    }
    return count;
}

// Function to check if a character array is a palindrome
bool checkPalindrome(char a[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        // Compare lowercase versions of both characters
        if (toLowerCase(a[s]) != toLowerCase(a[e]))
        {
            return false;

        }
        else
        {
            s++;
            e--;

        }
    }
    return true;
}


int main()
{
    char name[20];
    cout << "Enter a word to check: ";
    cin >> name;


    int len = getLength(name);
    if (checkPalindrome(name, len)){
        cout << name << " is a Palindrome!" << endl;
    } else {
        cout << name << " is NOT a Palindrome!" << endl;
    }

    return 0;
}

/*
OUTPUT:
Enter a word to check: Racecar
Racecar is a Palindrome!
*/