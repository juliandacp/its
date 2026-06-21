#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> playlist;

    playlist.push_back("Lagu A");
    playlist.push_back("Lagu B");
    playlist.push_back("Lagu C");

    cout << "Playlist:" << endl;

    for (string lagu : playlist)
        cout << lagu << endl;

    playlist.remove("Lagu B");

    cout << "\nSetelah menghapus Lagu B:\n";

    for (string lagu : playlist)
        cout << lagu << endl;

    return 0;
}