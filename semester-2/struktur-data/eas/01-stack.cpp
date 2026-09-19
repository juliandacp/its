#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> undoStack;
    stack<string> redoStack;

    undoStack.push("Tambah A");
    undoStack.push("Tambah B");
    undoStack.push("Tambah C");

    cout << "Undo: " << undoStack.top() << endl;

    redoStack.push(undoStack.top());
    undoStack.pop();

    cout << "Setelah Undo, aksi terakhir: "
         << undoStack.top() << endl;

    return 0;
}