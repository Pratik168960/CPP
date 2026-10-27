/*
    LECTURE 9: ARRAY SCOPE (PASS BY ADDRESS)


HOW SCOPE WORKS WITH ARRAYS:
- Normally, variables passed to a function are passed by "value" (a copy is made)

- However, when you pass an array to a function, C++ passes the base address
(the pointer to the first element)

- Because the function has the actual memory address, any updates made to the 
array inside the function will permanently alter the original array in main()
*/


#include <iostream>
using namespace std;


// Function to update the array
void update(int arr[], int n) {
    cout << endl << "Inside the update function..." << endl;
    

    // Updating the first element of the array
    arr[0] = 120;
    
    // Printing the array inside the custom function
    cout << "Printing in update function: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    cout << endl << "Going back to main function..." << endl << endl;
}



int main() {
    // Initialize an array of size 3
    int arr[3] = {1, 2, 3};

    
    // Call the function (passes the base address of 'arr' so the modification
    // takes place in original array not in the copy)
    update(arr, 3);

    
    // Print again in main to prove the original array was permanently modified
    cout << "Printing in main function: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
OUTPUT:

Inside the update function...
Printing in update function: 120 2 3 
Going back to main function...

Printing in main function: 120 2 3 
*/


