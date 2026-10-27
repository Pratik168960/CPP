/*
    LECTURE 9: INTRODUCTION TO ARRAYS

WHAT IS AN ARRAY?
- A data structure that stores a collection of elements of the SAME data type
- Elements are stored in contiguous (continuous) memory locations

- Example: Storing 5 integers (3, 5, 9, 2, 11) If the first is at memory 
address 100, the next is at 104, then 108, etc (since an int takes 4 bytes)

- The NAME of the array POINTS to the MEMORY LOCATION OF THE FIRST ELEMENT

WHY DO WE NEED ARRAYS?
- To store multiple variables of the same type under a single name, making
code cleaner and easier to manage
*/




// IMPLEMENTATION 

#include<iostream>
using namespace std ;

// Reusable function to print an integer array
void printArray(int arr[], int size) {
    cout << "Printing the array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Printing done!" << endl << endl;
}


int main (){

    // DECLARATION & ACCESS
    int friends[10]; // Declares an array of 10 integers (initially holds garbage values)

    friends[5] = 4;  // Accessing the 6th location (Remember: index starts at 0)
    cout << "Value at friends[5]: " << friends[5] << endl; 
    // OUTPUT -> Value at friends[5]: 4






    // INITIALIZATION
    int numbers[3] = {5, 7, 11}; // Initializing with specific values
    
    int allZeros[10] = {0}; // This initializes all elements to 0
    // Note: int allOnes[10] = {1}; does NOT set all to 1. It only sets the first to 1

    // How to initialize an entire array with a specific value
    int const SIZE = 10;
    int myArray[SIZE];
    int valueToFill = 7;
    
    cout << "myArray filled with 7s: ";
    for (int i = 0; i < SIZE; i++) {
        myArray[i] = valueToFill;
        cout << myArray[i] << " ";
    }
    cout << endl << endl;
    // OUTPUT -> myArray filled with 7s: 7 7 7 7 7 7 7 7 7 7








    // GARBAGE VALUES & OUT OF BOUNDS
    int number[15];
    // Since we haven't assigned a value, this will print a random garbage value
    cout << "Garbage value at number[0]: " << number[0] << endl << endl;
    // OUTPUT -> Garbage value at number[0]: 0 (or any random large integer)





    // PARTIAL INITIALIZATION
    int third[15] = {2, 7}; 
    // The first two elements are 2 and 7 remaining 13 elements automatically default to 0
    printArray(third, 15);
    // OUTPUT -> Printing the array: 2 7 0 0 0 0 0 0 0 0 0 0 0 0 0 





    // CALCULATING ARRAY SIZE 
    // If size of array is not given
    // sizeof() returns the total size in bytes
    // Divide by the size of a single element (int) to get the length
    int thirdSize = sizeof(third) / sizeof(int);
    cout << "Total elements in 'third' array: " << thirdSize << endl << endl;
    // OUTPUT -> Total elements in 'third' array: 15






    // ARRAYS OF OTHER DATA TYPES
    char ch[5] = {'a', 'b', 'c', 'r', 'p'};
    cout << "Character at ch[3]: " << ch[3] << endl;
    // OUTPUT -> Character at ch[3]: r
    
    // Note: We cannot use our printArray() function here because it only accepts 'int' arrays.
    cout << "Printing char array: ";
    for (int i = 0; i < 5; i++) {
        cout << ch[i] << " ";
    }


    cout << endl << endl << "Everything is fine!" << endl;  // this is to check does intialization is done or not 
    // OUTPUT -> Printing char array: a b c r p
    // OUTPUT -> Everything is fine!

    return 0;
}

/*
OUTPUT:
Value at friends[5]: 4
myArray filled with 7s: 7 7 7 7 7 7 7 7 7 7 

Garbage value at number[0]: 0

Printing the array: 2 7 0 0 0 0 0 0 0 0 0 0 0 0 0 
Printing done!

Total elements in 'third' array: 15

Character at ch[3]: r
Printing char array: a b c r p 

Everything is fine!
*/