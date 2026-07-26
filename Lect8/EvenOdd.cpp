#include<iostream>
using namespace std;


// Returns true if EVEN, false if ODD
bool isEven(int a){
    if(a&1){
        return 0; // The last bit is 1, so it's odd
    }
    return 1; // The last bit is 0, so it's even
}


int main (){
    int num;
    cout << "Enter a number :";
    cin >> num;


    // The if-statement evaluates the boolean returned by isEven()
    if(isEven(num)){
        cout << "Number is even" << endl; 
    } else {
        cout << "NUmber is odd" << endl;
    }
    return 0;
}