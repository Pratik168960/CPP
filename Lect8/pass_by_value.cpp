
// PASS BY VALUE -> copy created 

// When we pass a variable to a function, C++ does not send the actual 
// variable Instead, it sends a COPY of that variable's value 
// Changes made inside the function do not affect the original variable

#include<iostream>
using namespace std;


// The 'n' here is a completely separate copy belonging only to dummy()
void dummy (int n){
    n++;
    cout << "dummy n is " << n << endl;
}

int main (){
    int n;
    cout << "Enter a number n :";
    cin >> n;

    // We pass the value of 'n' to the dummy function
    dummy(n);

    // The original 'n' in main() remains unchanged!
    cout << "number n is " << n << endl;


    return 0;
}


// output 
// Enter a number n :15
// n is 16
// number n is 15


// WHY DOES THIS HAPPEN?
// main() has a variable named 'n' 
// dummy() also has a variable named 'n'
// They are completely different variables! 
// When main() calls dummy(n), a COPY of the value is created just for dummy()
// The increment (n++) only happened to dummy's copy original 'n' in main() is safe as it was