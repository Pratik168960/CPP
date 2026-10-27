// output-->
// Enter a value of n : 4
//    1
//   23
//  456
// 78910

// program 
#include<iostream>
using namespace std;

int main (){
    int n;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    int start = 1;
    while (i <= n){
        int space = n - i;
        while (space){
            cout << " ";
            space--;
        }
        int j = 1;
        

        while (j <= i){
            cout << start ;
            start++;
            j++;
        }
        cout << endl;
        i++;
    }
}