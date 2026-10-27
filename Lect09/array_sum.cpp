/*

    LECTURE 9: SUM OF ARRAY ELEMENTS

THE GOAL:
- Calculate the total sum of all the numbers stored in an array

HOW IT WORKS:
- We initialize a tracking variable called 'sum' to 0
- We traverse the array from the 0th index to the last index using a for loop
- During each iteration, we add the current element's value to our 'sum' variable
*/



#include <iostream>
using namespace std;


// Function to calculate and return the sum of the array
int getSum(int arr[], int size) {
    int sum = 0;
    
    // Traverse through each element of the array
    for (int i = 0; i < size; i++) {
        sum += arr[i]; // This is the same as: sum = sum + arr[i];
    }
    
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int arr[100]; 
    
    // Taking input from the user
    cout << "Enter " << size << " elements separated by spaces: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    // Call the function
    cout << "Sum of all elements in array is " << getSum(arr, size) << endl;
    
    return 0;
}

/*
OUTPUT :
Enter the size of the array: 5
Enter 5 elements separated by spaces: 5 8 10 2 1 
Sum of all elements in array is 26
*/