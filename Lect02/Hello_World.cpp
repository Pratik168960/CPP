// COMPILER 
// it handles the translation
// helps in finding error 


// IDE - INTEGRATED DEVELOPMENT ENVIRONMENT
// software that combines a code editor, compiler, and debugger into 
// one interface to help programmers write, test, and fix code 


// execution starts from int main start of program
// c++ has the functionality to print that is cout 

// int main (){
//     cout << "Hello World" << endl;
// }

// this will give error as compiler don't know what is cout here
// for that we need to add some library which contains the above keywords like cout and endl

#include<iostream>
using namespace std; 

int main (){
    cout << "Hello World" << endl;
}

// as we said c++ has print functionality already defined we don't need to write code for that 
// iostream is like a file where the code for cout is stored 
//imports the standard input-output stream library, allowing your program to read data 
//from the keyboard and print text to the screen


// c++ has many namespaces we have to use std namespace 
// tells the compiler to use the standard namespace, letting you write standard functions
// like cout and cin directly without typing the std:: prefix every time
// otherwise we would have to use std in every line of code 

// << >> what does this mean --> it is used to write std output
// << pushes data out to the screen
// >> pulls data in from the keyboard

// endl or '\n' --> new line or enter
// ; --> it is used for ending line it is like punctuation which tells compiler statement is complete 