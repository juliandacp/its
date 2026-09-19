#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    int* data = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
    }
    cout << endl << "Isi array:" << endl;
    for(int i = 0; i < n; i++) cout << data[i] << " ";
    delete[] data;
    return 0;
}