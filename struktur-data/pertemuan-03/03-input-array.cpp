#include <bits/stdc++.h>
using namespace std;

int main(){
    int nilai[5];
    for(int i = 0; i < 5; i++){
        cout << "Masukkan nilai ke-" << i << ": ";
        cin >> nilai[i];
    }
    cout << endl;
    cout << "Data yang dimasukkan: " << endl;
    for(int i = 0; i < 5; i++) cout << nilai[i] << endl;
    return 0;
}