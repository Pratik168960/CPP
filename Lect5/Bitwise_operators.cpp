// ********* BITWISE OPERATORS *********
// AND -> &
// OR  -> |
// NOT -> ~
// XOR -> ^

// these operators will work only on bit level

// AND (&) truth table
// x y z(x & y)
// 0 0 0
// 0 1 0
// 1 0 0
// 1 1 1 


// OR (|) truth table 
// x y z(x | y) 
// 0 0 0
// 0 1 1 
// 1 0 1 
// 1 1 1

// NOT (~) truth table 
// x z(~x)
// 0 1 
// 1 0
// a = 2 --> 000.....00010
// ~a --> 111.....11101
// print ~a 
// first bit 1 that means a negative number and take 2's complement of remaining bits
// 1's 000.....00010
// 2's 000.....00011
// ~a = -3

// XOR (^) truth table 
// x y z(x ^ y)
// 0 0 0  
// 0 1 1
// 1 0 1
// 1 1 0 

#include<iostream>
using namespace std;

int main (){
    int a = 4;
    int b = 6;

    cout << "a & b -> " << (a & b) << endl;
    cout << "a | b -> " << (a | b) << endl;
    cout << "~a -> " << ~a << endl;
    cout << "a ^ b -> " << (a ^ b) << endl;
    // output -->
    // a & b -> 4
    // a | b -> 6
    // ~a -> -5
    // a ^ b -> 2



// ********* LEFT SHIFT OPERATOR *********
// example 5 << 1 
// left shift 5 by 1 
// 5 => 000....00101
// 5 << 1 => 000....01010 ==> 10
// in general left shift multiplies the number by 2 but in case there is some big number 
// it will not for example 01000...0010 when we do left shift on this number the result will be 
// 1000...0100 that means it will be negative 

// ********* RIGHT SHIFT OPERATOR *********
// example 5 >> 2
// right shift 5 by 2 
// 5 => 000....00101
// 5 >> 2 => 000....00001
// in general right shift divides the number by 2 

// << >> if positive number then padding with 0 
// but in negative number it depends on compiler
    cout << (17 >> 1) << endl;   
    cout << (17 >> 2) << endl;
    cout << (19 << 1) << endl;
    cout << (19 << 2) << endl;




// ********* INCREMENT / DECREMENT OPERATOR *********
// i = i + 1;
// i += 1 ;
// i++ -> post increment : increment after operation
// ++i -> pre increment : increment before operation


// i = i - 1
// i -= 1 
// i-- -> post decrement 
// --i -> pre decrement

    int i = 7;
    cout << ++i << endl;
    cout << i++ << endl;
    cout << --i << endl;
    cout << i-- << endl;

}