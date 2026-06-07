#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int kapasitas, pilihan, data;
    cout << "Masukkan kapasitas queue: ";
    cin >> kapasitas;
    int *queue = new int[kapasitas];
    int front = 0;
    int rear = -1;
    do{
        cout << "\n===== MENU QUEUE =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                if(rear == kapasitas - 1) cout << "Queue penuh\n";
                else{
                    cout << "Masukkan data: ";
                    cin >> data;
                    queue[++rear] = data;
                }
                break;

            case 2:
                if(front > rear) cout << "Queue kosong\n";
                else cout << "Data yang dihapus: " << queue[front++] << endl;
                break;

            case 3:
                if(front > rear) cout << "Queue kosong\n";
                else{
                    cout << "Isi Queue:\n";
                    for(int i = front; i <= rear; i++) cout << queue[i] << " ";
                    cout << endl;
                }
                break;

            case 4:
                cout << "Program selesai\n";
                break;

            default:
                cout << "Pilihan tidak valid\n";
        }
    }while(pilihan != 4);
    delete[] queue;
    return 0;
}