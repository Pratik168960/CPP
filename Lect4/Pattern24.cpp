// output -->
// Enter a value of n : 5
//     1
//    22
//   333
//  4444
// 55555

// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while (i <= n){
        int space = n - i;
        while (space){
            cout << " ";
            space--;
        }
        int j = 1;
        while (j <= i){
            cout << i;
            j++;
        }
        cout << endl;
        i++;
    }
}