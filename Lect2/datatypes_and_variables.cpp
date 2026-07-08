// int a = 5 ;
// compiler gets to know that a is a variable of integer type which contains 5 value
// for which compiler needs to store 4 bytes
// from the datatype the compiler gets to know what type of data it is and how much memory will it require

// char ch = 'a' ;
// requires 1 byte

// bool or boolean --> true,1 or false,0
// 1 byte

// float f = 1.2 ;
// floating point number it requires 8 byte

// double d = 1.23 ;
// 8 byte

#include <iostream>
using namespace std;

int main()
{
   int a = 123;
   cout << a << endl;

   // char a = 'v';
   // cout << a << endl; // it will give error as we are redefining same variable name with different datatype
   // which creates confusion for compiler

   char b = 'v';
   cout << b << endl;

   bool bl = true;
   cout << bl << endl;

   float f = 1.2;
   cout << f << endl;

   double d = 1.23;
   cout << d << endl;

   int size = sizeof(a); // how much space is occupied
   cout << "size of a is : " << size << endl;

   // HOW DATA IS STORED ?
   // int a = 8 ;
   // int takes 4 bytes(32bits) memory
   // here 8 will be coverted into binary i.e 1000 so these 4 bits will
   // be stored at the the last bits lsb and others will be 0
   // 00000000....1000 in this way the data is stored in memory

   // char ch = 'a;
   // all the characters in c++ are mapped with some ASCII value
   // so a will be converted into its ascii value that is 97 which will be converted into binary and then will get stored in memory
   // char requires 1 byte (8bits)

   // what will happen if there are 32 bits
   // how will you or compiler identify whether it is a char or int
   // the answer is datatype

   // TYPE CASTING --> the process of manually or automatically converting a variable from one data type into another
   int c = 'a';
   cout << c << endl;
   // output --> 97

   char ch = 98;
   cout << ch << endl;
   // output --> b

   // integer -> 4 bytes -> 32 bits
   // max -> 2^31 - 1
   // min -> 0

   // char -> 1 byte -> 8 bits
   // max -> 2^8 - 1
   // min -> 0

   char ch1 = 123456;
   cout << ch1 << endl;
   // output --> @ with a warning implicit conversion from 'int' to 'char'
   // changes value from 123456 to 64
   //

   // 123456 is in int and we are trying to store it in 1 byte of char the
   // last byte of 123456 is 64 so it will be stored in char not 123456

   // how -ve are stored
   // it is determined by the first bit if its 0 then +ve , if 1 then -ve
   // suppose int a = -5
   // -> ignore the -ve sign convert into binary
   // -> take 2's complement and store

   unsigned int x = -112;
   cout << x << endl;
   // output -> 4294967184 a very large number
   // it only stores positive numbers range from 0 to 2^31 - 1 
   // as unsigned will consider the first bit msb as a part of number not for sign representation 
   // THIS SHOULD BE PREVENTED 

   // OPERATORS
   // Arithmetic operators -> +, -, *, /, %
   // Relational operators -> =, <, >, <=, >=, !=

   int i = 2;
   int j = 3;

   bool first = (a == b);
   cout << first << endl;

   bool second = (a > b);
   cout << second << endl;
   
   bool third = (a < b);
   cout << third << endl;
   
   bool fourth = (a >= b);
   cout << fourth << endl;

   bool fifth = (a <= b);
   cout << fifth << endl;
   
   bool sixth = (a != b);
   cout << sixth << endl;

   // Logical operators -> &&, ||, !

   int p = 23;
   cout << !p << endl;



}