// ********** CONDITIONALS **********
// as we saw in flowcharts we have a decision making block 
// which has two cases yes or no and do operation on that basis 
// so how it will be in code form 

// IF block 
// if (condition){
//     block of code     
// }
// if the condition is true then only block of code will be executed 

// IF ELSE block 
// if(condition){
//     block of code
// } else {
//     block of code 
// }
// if the condition is true then if block will be executed and if it is false then else block will be executed 

#include<iostream>
using namespace std; 

int main (){
    int n;
    cin >> n; // waits for the input
    cout << "Value of n is :" << n << endl;

    if (n > 0){
        cout << "n is positive" << endl;
    } else {
        cout << "n is negative" << endl;
    }

    // cin does not read space, tab, enter
    int a, b;
    cout << "Enter the value of a " << endl;
    cin >> a;
    cout << "Enter the value of b " << endl;
    cin >> b; 

    if (a > b){
        cout << "A is greater" << endl;
    }
    if (b > a){
        cout << "B is greater" << endl;
    }
    return 0; 
}