// output -->
// Enter temperature in F : 120
// Temperature in C is 48


// Program 
#include<iostream>
using namespace std;

int main (){
    int f, c ; 
    cout << "Enter temperature in F : " ; 
    cin >> f ; 

    c = ( f - 32 ) * 5 / 9 ; 


    cout <<"Temperature in C is " << c << endl ;


    return 0 ; 
}