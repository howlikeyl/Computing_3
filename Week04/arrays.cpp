#include <iostream>
using namespace std;
int main (){
    int n[] = {7,5,6,7,8,9,10};
    int size = sizeof(n) / sizeof(n[0]);
    cout << size << endl;
    string a [] = {"name", "hello", "apple"};
    string b = a[2].substr(0, 3);
    cout << b << endl;
    // substracting string into group of arrays
    string c = "123456789";
    // substracting string from index 1 which is 2 and conrain 4 character
    string d = c.substr(1, 4);
    cout << d << endl;
    cout << d[2] << endl;  // display the index 2 which is 4 , d[2] DOES NOT mean d is arrays, d is string, and when you use d[1], you're accessing the character at index 1 of the string.
    sort(n, n+size); //formular for sorted arrays
    for (int i = 0; i < size; i++){
        cout << n[i];
    }
    cout << endl;
    // for (int i = 0; i < size; i++){
    //     cout << "enter number: ";
    //     int j;
    //     cin >> j;
    // }

    // pointer
    int arr[] = {1,2,3,4,5};
    // create pointer p
    int* p;
    // point p to arrays arr
    p = arr;
    // display value at index 1
    cout << *p << endl; // or p[0]
    // display valuee at index2
    *p++;
    cout << *p << endl; //o or p[1]

    return 0;
}