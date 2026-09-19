#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int kapasitas = 10;
    string *stack = new string[kapasitas];
    string *queue = new string[kapasitas];
    int top = -1;
    int front = 0;
    int rear = -1;
    int pilihan;
    string barang;
    do{
        cout << "\n=== SISTEM GUDANG ===\n";
        cout << "1. Simpan Barang (Stack)\n";
        cout << "2. Ambil Barang (Stack)\n";
        cout << "3. Tampilkan Stack\n";
        cout << "4. Tambah Antrian Barang (Queue)\n";
        cout << "5. Ambil Barang dari Antrian (Queue)\n";
        cout << "6. Tampilkan Queue\n";
        cout << "7. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                if(top == kapasitas - 1) cout << "Gudang stack penuh\n";
                else{
                    cout << "Nama barang: ";
                    cin >> barang;
                    stack[++top] = barang;
                    cout << "Barang disimpan\n";
                }
                break;

            case 2:
                if(top == -1) cout << "Stack kosong\n";
                else cout << "Barang diambil: " << stack[top--] << endl;
                break;

            case 3:
                if(top == -1) cout << "Stack kosong\n";
                else{
                    cout << "Isi stack:\n";
                    for(int i = top; i >= 0; i--) cout << stack[i] << endl;
                }
                break;

            case 4:
                if(rear == kapasitas - 1) cout << "Queue penuh\n";
                else{
                    cout << "Nama barang: ";
                    cin >> barang;
                    queue[++rear] = barang;
                    cout << "Barang masuk antrian\n";
                }
                break;

            case 5:
                if(front > rear) cout << "Queue kosong\n";
                else cout << "Barang keluar: " << queue[front++] << endl;
                break;

            case 6:
                if(front > rear) cout << "Queue kosong\n";
                else{
                    cout << "Isi queue:\n";
                    for(int i = front; i <= rear; i++) cout << queue[i] << endl;
                }
                break;

            case 7:
                cout << "Program selesai\n";
                break;

            default:
                cout << "Pilihan tidak valid\n";
        }
    }while(pilihan != 7);
    delete[] stack;
    delete[] queue;
    return 0;
}