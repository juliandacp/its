#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Barang{
    int id;
    string nama;
    int jumlah;
    string tanggal;
};

int main(){
    int kapasitas = 10;
    Barang *stack = new Barang[kapasitas];
    Barang *queue = new Barang[kapasitas];
    int top = -1;
    int front = 0;
    int rear = -1;
    int pilihan;
    do{
        cout << "\n====================================\n";
        cout << "      SISTEM INVENTORI GUDANG\n";
        cout << "====================================\n";
        cout << "1. Barang Masuk Gudang\n";
        cout << "2. Ambil Barang dari Gudang\n";
        cout << "3. Tampilkan Isi Gudang\n";
        cout << "4. Masukkan Barang ke Antrian Kirim\n";
        cout << "5. Kirim Barang\n";
        cout << "6. Tampilkan Antrian Pengiriman\n";
        cout << "7. Exit\n";
        cout << "------------------------------------\n";
        cout << "Pilih Menu: ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                if(top == kapasitas - 1) cout << "Gudang penuh!\n";
                else{
                    Barang b;
                    cout << "ID Barang      : ";
                    cin >> b.id;
                    cout << "Nama Barang    : ";
                    cin >> b.nama;
                    cout << "Jumlah Barang  : ";
                    cin >> b.jumlah;
                    cout << "Tanggal Masuk  : ";
                    cin >> b.tanggal;
                    stack[++top] = b;
                    cout << "Barang berhasil disimpan di gudang\n";
                }
                break;

            case 2:
                if(top == -1) cout << "Gudang kosong\n";
                else{
                    cout << "Barang diambil: " << stack[top].nama << endl;
                    top--;
                }
                break;

            case 3:
                if(top == -1) cout << "Gudang kosong\n";
                else{
                    cout << "\nDATA BARANG DI GUDANG\n";
                    cout << left << setw(10) << "ID"
                         << setw(15) << "Nama"
                         << setw(10) << "Jumlah"
                         << setw(15) << "Tanggal\n";
                    for(int i = top; i >= 0; i--) cout << setw(10) << stack[i].id << setw(15) << stack[i].nama << setw(10) << stack[i].jumlah << setw(15) << stack[i].tanggal << endl;
                }
                break;

            case 4:
                if(front > rear) cout << "Tidak ada barang di gudang\n";
                else if(rear == kapasitas - 1) cout << "Antrian penuh\n";
                else{
                    queue[++rear] = stack[top--];
                    cout << "Barang masuk antrian pengiriman\n";
                }
                break;

            case 5:
                if(front > rear) cout << "Tidak ada barang dalam antrian\n";
                else{
                    cout << "Barang dikirim: " << queue[front].nama << endl;
                    front++;
                }
                break;

            case 6:
                if(front > rear) cout << "Antrian kosong\n";
                else{
                    cout << "\nANTRIAN PENGIRIMAN\n";
                    cout << left << setw(10) << "ID" << setw(15) << "Nama" << setw(10) << "Jumlah" << setw(15) << "Tanggal\n";
                    for(int i = front; i <= rear; i++) cout << setw(10) << queue[i].id << setw(15) << queue[i].nama << setw(10) << queue[i].jumlah << setw(15) << queue[i].tanggal << endl;
                }
                break;

            case 7:
                cout << "Program selesai\n";
                break;

            default:
                cout << "Pilihan tidak tersedia\n";
        }
    }while(pilihan != 7);
    delete[] stack;
    delete[] queue;
    return 0;
}