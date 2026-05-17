#include <bits/stdc++.h>
using namespace std;

struct mahasiswa{
    int umur;
    string nrp, nama, jurusan, hobi[3];
};

int main(){
    mahasiswa mhs[3];
    for(int i = 0; i < 3; i++){
        cout << "Data mahasiswa ke-" << i + 1 << ": " << endl;
        cout << "NRP: ";
        cin >> mhs[i].nrp;
        cin.ignore(); 
        cout << "Nama: ";
        getline(cin, mhs[i].nama);
        cout << "Jurusan: ";
        getline(cin, mhs[i].jurusan);
        cout << "Umur: ";
        cin >> mhs[i].umur;
        cin.ignore();
        cout << "Masukkan tiga hobi: " << endl;
        for(int j = 0; j < 3; j++){
            cout << "Hobi ke-" << j + 1 << ": ";
            getline(cin, mhs[i].hobi[j]);
        }
        cout << endl;
    }
    cout << endl;
    cout << "===== DATA MAHASISWA =====" << endl;
    for(int i = 0; i < 3; i++){
        cout << "Mahasiswa ke-" << i + 1 << ": " <<endl;
        cout << "NRP: " << mhs[i].nrp << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "Jurusan: " << mhs[i].jurusan << endl;
        cout << "Umur: " << mhs[i].umur << endl;
        cout << "Hobi: ";
        for(int j = 0; j < 3; j++){
            cout << mhs[i].hobi[j];
            if(j < 2) cout << ", ";
        }
        cout << endl << endl;
    }
    return 0;
}