
// N-TH TERM OF A SEQUENCE (Arithmetic Progression)

// This program calculates the n-th term of a specific 
// mathematical sequence using the formula: Term = (3 * n) + 7

#include<iostream>
using namespace std ;

// Function to calculate the n-th term
int nth_term(int num){
    int result = (3 * num) + 7;
    return result;
}

int main (){

    int n;
    cout << "enter a number n :";
    cin >> n;

    // Call the function and print the returned value
    cout << "Result is " << nth_term(n);

    return 0 ; 
}