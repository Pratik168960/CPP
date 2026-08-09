/*
    LECTURE 9: LINEAR SEARCH

WHAT IS LINEAR SEARCH?
- It is a simple algorithm to find a specific element ("key") in an array

- How it works: We traverse the array from the 0th index to the last index, 
comparing each element with key

- If a match is found, we immediately return true (1)

- If we check every single element and no match is found, the loop ends 
and we return false (0)
*/


#include <iostream>
using namespace std;


// Function
bool search(int arr[], int size, int key) {

    // Traverse entire array
    for (int i = 0; i < size; i++) {
    
        // Compare current element with the key
        if (arr[i] == key) {
            return true; // Match found
        }
    }

    // If the loop completes without returning, the key is not in the array
    return false; 
}


int main() {

    int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;
    

    // Call the search function
    // We pass the array, its size (10), and the key to find
    bool found = search(arr, 10, key);
    


    if (found) {
        cout << "Key is present " << endl;
    } else {
        cout << "Key is absent " << endl;
    }
    
    return 0;
}


/*
OUTPUT:
Enter the element to search for: -2
Key is present

Enter the element to search for: 12
Key is absent
*/