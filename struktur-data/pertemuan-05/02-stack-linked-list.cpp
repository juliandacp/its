#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Struktur Node
struct Node{
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;

public:
    // Constructor
    Stack(){
        top = NULL;
    }
    // Push
    void push(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " ditambahkan ke stack\n";
    }
    // Pop 
    void pop(){
        if (top == NULL){
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << temp->data << " dihapus dari stack\n";
        top = top->next;
        delete temp;
    }
    // Peek
    void peek(){
        if(top == NULL) cout << "Stack kosong\n";
        else cout << "Elemen teratas: " << top->data << endl;
    }
    // Cek kosong
    bool isEmpty(){
        return (top == NULL);
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.pop();
    s.peek();
    return 0;
}