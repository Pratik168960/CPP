
// TOTAL SET BITS IN TWO NUMBERS

// This program counts how many bits are set to '1'
#include<iostream>
using namespace std;

// Function to count the set bits (1s) in a single number
int set_bits(int num){
    int count = 0;
    // The loop runs until all the 1s are shifted out and the number becomes 0
    while(num !=0 ){
        // (num & 1) isolates the very last (rightmost) bit
        // If it is equal to 1, we increase our count
        if((num&1) == 1){
            count++;
        }
        // Shift all the bits to the right by 1 position.
        num = num >> 1;
    }
    return count;
}

int main(){

    int a, b;
    cout << "Enter a value of a : ";
    cin >> a;

    cout << "Enter a value of b : ";
    cin >> b;

    int result = set_bits(a) + set_bits(b);
    cout << "Total set bits in a and b is " << result << endl;
    return 0;
}


// output 
// Enter a value of a : 2
// Enter a value of b : 3
// Total set bits in a and b is 3