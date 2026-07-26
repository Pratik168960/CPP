// ***** FUNCTIONS *****

// till now we were writing code for every task 
// but what if there comes a case we want to perform a same task multiple times 
// we have to write code again and again this leads to bulky, buggy, and hard to read code


// in alternative we can use function which will do same task without writing code again n again 
// A function is a reusable block of code that has a well-defined task

#include<iostream>
using namespace std;

// function declaration
// syntax :
// return_type function_name(i/p parameters){
//      block of code
//      return value ;
// }

// 1. FUNCTION WITH PARAMETERS & RETURN VALUE
// This function calculates 'a' raised to the power of 'b' (a^b)
int power(int a, int b) {
    int ans = 1;
    
    for (int i = 1; i <= b; i++) {
        ans = ans * a;
    }
    
    return ans;
}


// 2. VOID FUNCTION (No return value)
// 'void' means this function performs a task but does not return a value
void printGreeting() {
    cout << "Greetings!" << endl;
}



// MAIN FUNCTION

int main (){
    // Calling our void function
    printGreeting();
    cout << endl;

    // Testing our power function
    int a, b;
    cin >> a >> b;

    // We call power(a, b) and store what it returns inside 'result'
    int result = power(a, b);
    cout << "Result is" << result <<  endl;


    return 0;
}