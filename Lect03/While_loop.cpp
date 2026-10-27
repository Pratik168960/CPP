// WHILE loop

// while(condition){
//     block of code
// }
// execute the block of code as long as the condition is true 

// Print 1 to N 
#include<iostream>
using namespace std ;

int main (){
    int n ;
    cin >> n;

    int i = 1;

    while(i <= n){
        cout << i << " ";
        i++;
    }
}