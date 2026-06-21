#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> pasien;

    pasien.push("Andi");
    pasien.push("Budi");
    pasien.push("Citra");

    while (!pasien.empty()) {
        cout << "Melayani: "
             << pasien.front() << endl;
        pasien.pop();
    }

    return 0;
}