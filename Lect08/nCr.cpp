
// COMBINATIONS (nCr) CALCULATOR
// This program calculates the number of combinations (nCr).
// Formula: nCr = n! / (r! * (n - r)!)

#include<iostream>
using namespace std ;

// 1. Helper Function: Calculates the factorial of a number (n!)
int factorial (int n){
    int fact = 1;
    for (int i = 1; i <= n; i++){
        fact = fact * i;
    }
    return fact;
}

// 2. Main Logic Function: Calculates nCr using the helper function
int nCr(int n, int r){
    // We call our factorial function 3 separate times to build the formula
    int num = factorial(n);   
    int denom = factorial(r) * factorial(n - r);

    int ans = num / denom;
    return ans;
}


int main (){
    int n, r;
    cout << "Enter value of n, r :";
    cin >> n >> r;

    cout << "Answer is " << nCr(n, r) << endl;
    return 0;
}