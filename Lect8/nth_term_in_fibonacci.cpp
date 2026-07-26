
// N-TH TERM IN FIBONACCI SEQUENCE
// Sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21...
#include<iostream>
using namespace std ;


int nth_fibonacci(int num){
    // Base cases: the 1st and 2nd terms are fixed and do not need calculation
    if (num == 1) return 0;
    if (num == 2) return 1;

    int a = 0; 
    int b = 1; 
    
    int term = 0; 

    // Start calculating from the 3rd term up to the requested 'num'
    for (int i = 3; i <= num; i++) {
        // The current term is always the sum of the previous two
        term = a + b;
        
        // Shift our variables forward so we are ready for the next loop
        a = b;
        b = term;
    }
    
    return term;
}

int main (){
    int n;
    cout << "Enter a term number (n) : ";
    cin >> n;

    // Call the function and directly print the returned result
    cout << n << "-th term in fibonacci is " << nth_fibonacci(n) << endl;
    

    return 0;
}