// output -->
// Enter a value of n : 5
// 1 
// 2 3 
// 3 4 5 
// 4 5 6 7 
// 5 6 7 8 9 

// program 
#include<iostream>
using namespace std;

// int main (){
//     int n ;
//     cout << "Enter a value of n : ";
//     cin >> n;

//     int i = 1;
//     while(i <= n){
//         int j = 1;
//         int value = i;
//         while(j <= i){
//             cout << value << " ";
//             value++;
//             j++;
//         }
//         cout << endl;
//         i++;
//     }
// }

// OR without using extra variable named value 

int main() {
    int n ;
    cout << "Enter a value of n : ";
    cin >> n;

    int i = 1;
    while(i <= n){
        int j = 1;
        while(j <= i){
            cout << i + j - 1;
            j++;
        }
        cout << endl;
        i++;
    }
}