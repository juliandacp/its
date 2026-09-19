#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int kapasitas, pilihan, data;
    cout << "Masukkan kapasitas stack: ";
    cin >> kapasitas;
    int *stack = new int[kapasitas];
    int top = -1;
    do{
        cout << "\n===== MENU STACK =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                if(top == kapasitas - 1) cout << "Stack Overflow\n";
                else{
                    cout << "Masukkan data: ";
                    cin >> data;
                    stack[++top] = data;
                }
                break;

            case 2:
                if(top == -1) cout << "Stack kosong\n";
                else cout << "Data yang dihapus: " << stack[top--] << endl;
                break;

            case 3:
                if(top == -1) cout << "Stack kosong\n";
                else{
                    cout << "Isi Stack:\n";
                    for(int i = top; i >= 0; i--) cout << stack[i] << " ";
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
    delete[] stack;
    return 0;
}