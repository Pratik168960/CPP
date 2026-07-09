// output -->
// Enter a value for n : 5
// 1
// 22
// 333
// 4444
// 55555

// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value for n : ";
    cin >> n;

    int i = 1;
    while (i <= n){
        int j = 1;
        while(j <= i){
            cout << i;
            j++;
        }
        cout << endl;
        i++;

    }
}