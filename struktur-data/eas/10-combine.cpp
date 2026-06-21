#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
using namespace std;

int main() {

    // Hash Table (Login User)
    unordered_map<string,string> user;
    user["fajar"] = "123";

    // Queue (Antrian Pesanan)
    queue<string> pesanan;
    pesanan.push("Nasi Goreng");
    pesanan.push("Mie Ayam");

    // Linked List (Riwayat)
    list<string> riwayat;

    // Priority Queue (Driver)
    priority_queue<int> driver;
    driver.push(5);
    driver.push(8);

    // Stack (Undo)
    stack<string> undo;
    undo.push("Pesan Nasi Goreng");

    cout << "Pesanan pertama: "
         << pesanan.front() << endl;

    cout << "Driver terbaik: "
         << driver.top() << endl;

    cout << "Undo terakhir: "
         << undo.top() << endl;

    return 0;
}