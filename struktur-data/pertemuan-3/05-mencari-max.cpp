#include <bits/stdc++.h>
using namespace std;

int main(){
    int nilai[5], maximum;
    for(int i = 0; i < 5; i++){
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }
    maximum = nilai[0];
    for(int i = 1; i < 5; i++){
        if(nilai[i] > maximum) maximum = nilai[i];
    }
    cout << endl;
    cout << "Nilai tertinggi adalah: " << maximum << endl;
    return 0;
}