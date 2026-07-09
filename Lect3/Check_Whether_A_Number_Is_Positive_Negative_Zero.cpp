#include<iostream>
using namespace std;

int main (){
    int a;
    cout << "Enter a number to check:" << endl;
    cin >> a;

    if(a>0){
        cout << "A is positive" << endl;
    } else {
        if(a<0){
            cout << "A is negative" << endl;
        } else {
            cout << "A is 0" << endl;
        }
    }

    // or 

    if (a>0){
        cout << "A is positive" << endl;
    } else if (a<0){
        cout << "A is negative" << endl;
    } else {
        cout << "A is 0" << endl;
    }
}