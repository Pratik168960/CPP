#include<iostream>
using namespace std;

int main(){
    char ch;
    cout << "Enter a value to check:" << endl;
    cin >> ch;

    if ('A'<= ch && ch <= 'Z'){
        cout << "Uppercase" << endl;
    } else if ('a' <= ch && ch <= 'z'){
        cout << "Lowercase" << endl;
    } else if ('0' <= ch && ch <= '9'){
        cout << "Numeric" << endl;
    }
}