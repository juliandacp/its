#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 10;
string antrian[MAX];
int front = -1, rear = -1;

void enqueue(string data){
    if(rear == MAX - 1){
        cout << "Antrian penuh" << endl;
        return;
    }
    if(front == -1) front = 0;
    rear++;
    antrian[rear] = data;
    cout << data << " masuk antrian" << endl;
}

void dequeue(){
    if(front == -1 || front > rear){
        cout << "Antrian kosong" << endl;
        return;
    }
    cout << antrian[front] << " sedang dilayani\n";
    front++;
    if(front > rear) front = rear = -1;
}

void display() {
    if(front == -1 || front > rear){
        cout << "Antrian kosong\n";
        return;
    }
    cout << "Isi antrian: ";
    for (int i = front; i <= rear; i++){
        cout << antrian[i] << " ";
    }
    cout << endl;
}

int main() {
    enqueue("A");
    enqueue("B");
    enqueue("C");
    display();
    cout << endl;
    dequeue();
    display();
    cout << endl;
    enqueue("D");
    display();
    cout << endl;
    return 0;
}