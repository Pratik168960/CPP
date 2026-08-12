/*

    LECTURE 10: FIND UNIQUE ELEMENT IN AN ARRAY


GOAL:
- You are given an array of size N (where N is always odd)

- Every element in the array appears exactly TWICE, except for one 
element which appears only ONCE. Find that unique element

- Example: [2, 3, 1, 6, 3, 6, 2] -> The unique element is 1.

Similar to how we simplify mathematical expressions by canceling out terms with 
opposite signs (e.g., 10 - 10 + 10 - 10 + 1), we should apply the same principle here 

THE OPTIMAL APPROACH (Using XOR):
- Property 1: a ^ a = 0 
- Property 2: a ^ 0 = a 
- Therefore, if we XOR all the elements in the array together, the 
duplicate pairs will cancel each other out (become 0)
- The only thing left will be the unique number!
*/

#include <iostream>
using namespace std;


// Only this function part of this code is required on CodingNinjas question 
// Function to find the unique element
int findUnique(int arr[], int size) {
    int ans = 0;
    
    // Traverse the array and XOR all elements together
    for (int i = 0; i < size; i++) {
        ans = ans ^ arr[i]; // XOR the current element with our running total
    }
    
    return ans;
}





int main() {
    // Initialize an array where every number repeats twice except for '4'
    int arr[7] = {2, 3, 1, 6, 3, 6, 2};
    int size = 7;
    
    cout << "Array elements: ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the function
    int uniqueElement = findUnique(arr, size);
    
    cout << "The unique element in the array is: " << uniqueElement << endl;

    return 0;
}

/*
OUTPUT:
Array elements: 2 3 1 6 3 6 2 
The unique element in the array is: 1
*/