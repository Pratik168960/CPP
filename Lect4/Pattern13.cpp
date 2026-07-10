// output -->
// Enter a value of n : 4
// A B C D 
// E F G H 
// I J K L 
// M N O P

// Program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    char ch = 'A';
    while (i <= n){
        int j = 1;
        while (j <= n){
            cout << ch << " ";
            ch++;
            j++;
        }
        cout << endl;
        i++;
    }
}