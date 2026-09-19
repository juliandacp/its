#include <bits/stdc++.h>
using namespace std;

int main(){
    int var;
    cin >> var;
    int *ptr = &var;
    cout << "Value of x: " << var << endl;
    cout << "Address of x: " << &var << endl;
    cout << "Value stored in pointer ptr: " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    return 0;
}