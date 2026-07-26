// ******* SWITCH CASE *******
// If-else-if ladders can get too messy when checking the same variable against 
// multiple specific values. That's where the 'switch' statement comes in!


// syntax :
// switch(integral expression){
//     case const1 :
//         block of code and break; 
//     case const2 :
//         block of code and break;
//     and so on ..

//     if no condition satisfies then there is default case
//     default:
//         block of code
// }

#include<iostream>
using namespace std;

int main (){

    int num = 2;
    cout << endl;
    switch(num){
        case 1 :
            cout << "First" << endl;
            break; // if we want no execution after this case  
        case 2:
            cout << "Second" << endl;
            break;
        default: cout << "It is default case" << endl;
    }
    cout << endl;

// output --> Second


// if we used switch inside an infinite loop how to get out of it 
// while(1){
//     switch(){
//         block of code 
//         break 
//     }
// }
// break only get us outside the switch but how to get out from loop 

// we have to use EXIT 
// exit() immediately terminates the entire program and returns a status 
// code to the operating system, completely skipping any remaining code
// and local object destructors.





// CONTINUE is not valid in switch 
// because continue is designed to skip to the next iteration of a loop, 
// but a switch is just a conditional branching statement, not a loop.



// CALCULATOR

    int a, b;
    cout << "Enter the value of a : ";
    cin >> a;

    cout << "Enter the value of b : ";
    cin >> b;

    char op;
    cout << "Enter the operator(+, -, *, /, %) : ";
    cin >> op;

    switch(op){
        case '+' :
            cout << (a + b) << endl;
            break;
        case '-' :
            cout << (a - b) << endl;
            break;
        case '*' :
            cout << (a * b) << endl;
            break;
        case '/' :
            cout << (a / b) << endl;
            break;
        case '%' :
            cout << (a % b) << endl;
            break;
        default :
            cout << "Please enter a valid operator" << endl;
    }

// output -->
// Enter the value of a : 5
// Enter the value of b : 3
// Enter the operator : *
// 15


    int amt;
    cout << "Enter total amount: ";
    cin >> amt;

    int step = 1; // Dummy variable to start the switch



    switch (step) {

        // Notice there are NO 'break' statements here! 
        // This is called "fall-through". Once case 1 triggers, it will automatically 
        // fall down and execute case 2, then case 3, then case 4 in order.
        case 1:
            cout << "100 Rupee notes : " << amt / 100 << endl;
            amt %= 100; 
            
        case 2:
            cout << "50 Rupee notes  : " << amt / 50 << endl;
            amt %= 50;
            
        case 3:
            cout << "20 Rupee notes  : " << amt / 20 << endl;
            amt %= 20;
            
        case 4:
            cout << "1 Rupee coins   : " << amt << endl;
    }

    return 0; 
}