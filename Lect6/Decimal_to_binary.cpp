// ******** Decimal to binary ********

// 1ST APPROACH
// steps :
// divide by 2 
// store remainder in answer
// repeat above steps until n != 0
// reverse the result 


// n = 10
// division    rem 
// 10/2        0
// 5/2         1
// 2/2         0
// 1/2         1 
// => 0101 reverse this ==> 1010 i.e 10 in decimal 



// 2ND APPROACH
// using & operator 
// answer = 0
// while (n != 0)
// bit = n & 1 
// answer = (pow(10,0) * digit) + answer
// n = n >> 1 

 



// if there are 3 digit 1, 2, 3
// if we want them in serial order and get a single integer 
// ans = (ans * 10) + digit 

// if we want reverse order 
// ans = (digit * pow(10,i)) + answer 




#include<iostream>
#include<math.h>
using namespace std ;

int main (){
    int n;
    cout << "Enter a number : ";
    cin >> n;

    int ans = 0;
    int i = 0;
    while(n != 0){
        int bit = n&1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }

    cout << "Answer is " << ans << endl;




// for -ve number 
// n = -6 
// steps 
// ignore the negative sign 
// take 2's complement of 6 

// 6 -> 000...0110
// 1's -> 111...1001
// 2's -> 111...1010 

// now to print checking first bit it is 1 that means negative 
// and 2's complement of remaining bits 
// 1's -> 00...0101
// 2's -> 00...0110

// result => -6 



    int m;
    cout << "Enter a number : ";
    cin >> m;

    cout << "Answer is ";
    
    // Loop exactly 32 times, from the leftmost bit (31) down to the rightmost (0)
    for (int i = 31; i >= 0; i--) {
        // Shift the bit we care about to the end, then AND it with 1
        int bit = (m >> i) & 1;
        cout << bit;
    }
    
    cout << endl;




}