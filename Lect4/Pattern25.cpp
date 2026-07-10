// output -->
// Enter a value of n : 5
// 12345
//  2345
//   345
//    45
//     5

// program
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while (i <= n){
        int space = i - 1;
        while(space){
            cout << " ";
            space--;
        }
        int j = 1;
        while(j <= n - i + 1){
            cout << i+j-1;
            j++;
        }
        cout << endl;
        i++;
    }
}