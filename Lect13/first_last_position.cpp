/*

        LECTURE 13: FIRST AND LAST POSITION OF AN ELEMENT


GOAL:
- Given a sorted array with duplicate elements, find the index of the 
very first occurrence and the very last occurrence of a given key

APPROACH:
- We use Binary Search to keep the time complexity at O(log N)
- FIRST OCCURRENCE: 
When arr[mid] == key, we store 'mid' as our potential answer, but we 
update 'end = mid - 1' to keep searching in the LEFT half for earlier occurrences.
- LAST OCCURRENCE: 
When arr[mid] == key, we store 'mid' as our potential answer, but we 
update 'start = mid + 1' to keep searching in the RIGHT half for later occurrences.
*/


#include <iostream>
using namespace std;


// Function to find the very first occurrence of a key
int firstOccurrence(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1; // Default if the key is not found

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid;         // Store the answer
            end = mid - 1;     // Keep looking left for an earlier occurrence
        }
        else if (key > arr[mid]) {
            start = mid + 1;   // Go to the right half
        }
        else {
            end = mid - 1;     // Go to the left half
        }
    }
    return ans;
}



// Function to find the very last occurrence of a key
int lastOccurrence(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1; // Default if the key is not found

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            ans = mid;         // Store the answer
            start = mid + 1;   // Keep looking right for a later occurrence
        }
        else if (key > arr[mid]) {
            start = mid + 1;   // Go to the right half
        }
        else {
            end = mid - 1;     // Go to the left half
        }
    }
    return ans;
}



int main() {
    // The array MUST be sorted for Binary Search
    int evenArray[11] = {1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 5};
    int key = 3;

    cout << "Array elements: 1 2 3 3 3 3 3 3 3 3 5" << endl;
    cout << "Target Key: " << key << endl << endl;
    
    // Find the occurrences
    int first = firstOccurrence(evenArray, 11, key);
    int last = lastOccurrence(evenArray, 11, key);

    cout << "First occurrence of " << key << " is at index " << first << endl;
    cout << "Last occurrence of " << key << " is at index " << last << endl;

    // BONUS: Find total number of occurrences using the formula
    // Total Occurrences = (Last Index - First Index) + 1
    if (first != -1 && last != -1) {
        int total = (last - first) + 1;
        cout << "Total number of occurrences is " << total << endl;
    } else {
        cout << "Total number of occurrences is 0" << endl;
    }

    return 0;
}

/*
OUTPUT:
Array elements: 1 2 3 3 3 3 3 3 3 3 5
Target Key: 3

First occurrence of 3 is at index 2
Last occurrence of 3 is at index 9
Total number of occurrences is 8
*/