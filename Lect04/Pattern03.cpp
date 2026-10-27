// output -->
// Enter a value for n : 4
// 1234
// 1234
// 1234
// 1234


// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value for n : ";
    cin >> n;

    int i = 1;
    while (i<=n){
        int j = 1;
        while(j<=n){
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
}