/*
    LECTURE 9: MAXIMUM AND MINIMUM IN AN ARRAY 

THE GOAL:
- Find the largest (maximum) and smallest (minimum) values in an array.

INT_MAX & INT_MIN:
- C++ provides built-in macros (inside <climits>) that represent the 
largest and smallest possible integer values
- We initialize our 'maxi' variable to INT_MIN (the lowest possible number) 
so any number in the array will be larger and replace it.
- We initialize our 'mini' variable to INT_MAX (the highest possible number) 
so any number in the array will be smaller and replace it.
*/




#include <iostream>
using namespace std;




// Function to find the minimum value in the array
int getMin(int num[], int n) {
    int mini = INT_MAX; // Start with the highest possible integer (2^31 - 1)
    
    for (int i = 0; i < n; i++) {
        // If the current element is smaller than 'mini', update 'mini'
        if (num[i] < mini) {
            mini = num[i];
        }
        
        // NOTE: You can also use the built-in C++ function like this:
        // mini = min(mini, num[i]);
    }
    return mini;
}




// Function to find the maximum value in the array
int getMax(int num[], int n) {
    int maxi = INT_MIN; // Start with the lowest possible integer (-2^31)
    
    for (int i = 0; i < n; i++) {
        // If the current element is larger than 'maxi', update 'maxi'
        if (num[i] > maxi) {
            maxi = num[i]; 
        }
        
        // NOTE: You can also use the built-in C++ function like this:
        // maxi = max(maxi, num[i]); 
    }
    // returning max value 
    return maxi;
}




int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    // int num[size] -> size is a variable bad practice 

    // Good practice: declare an array with a maximum expected size based on constraints
    int num[100]; 
    
    cout << "Enter " << size << " elements separated by spaces: ";
    // taking input in array 
    for (int i = 0; i < size; i++) {
        cin >> num[i]; 
    }
    
    cout << "Maximum value is: " << getMax(num, size) << endl;
    cout << "Minimum value is: " << getMin(num, size) << endl;
    
    return 0;
}

/*
OUTPUT (If user inputs size 5, and elements 3 10 4 81 2):
Enter the size of the array: 5
Enter 5 elements separated by spaces: 3 10 4 81 2

Maximum value is: 81
Minimum value is: 2
*/