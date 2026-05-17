#include <bits/stdc++.h>
using namespace std;

struct mahasiswa{
    string nim, nama, prodi;
    float ipk;
};

int main(){
    mahasiswa mhs1, mhs2;
    mhs1.nim = "5025251028";
    getline(cin, mhs1.nama);
    getline(cin, mhs1.prodi);
    cin >> mhs1.ipk;
    cin.ignore();
    mhs2.nim = "5025251059";
    getline(cin, mhs2.nama);
    cout << endl << "Mahasiswa 1:" << endl;
    cout << "NIM: " << mhs1.nim << endl;
    cout << "Nama: " << mhs1.nama << endl;
    cout << "Prodi: " << mhs1.prodi << endl;
    cout << "IPK: " << mhs1.ipk << endl << endl;
    cout << "Mahasiswa 2:" << endl;
    cout << "NIM: " << mhs2.nim << endl;
    cout << "Nama: " << mhs2.nama << endl;
    return 0;
}