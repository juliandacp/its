#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Queue{
private:
    int *arr;
    int front, rear;
    int kapasitas;

public:
    Queue(int size){
        kapasitas = size;
        arr = new int[kapasitas];
        front = 0;
        rear = -1;
    }
    void enqueue(int x){
        if(rear == kapasitas - 1){
            cout << "Queue penuh\n";
            return;
        }
        arr[++rear] = x;
    }
    void dequeue(){
        if(front > rear){
            cout << "Queue kosong\n";
            return;
        }
        cout << "Elemen yang dihapus: " << arr[front++] << endl;
    }
    void display(){
        if(front > rear){
            cout << "Queue kosong\n";
            return;
        }
        for(int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
    ~Queue(){
        delete[] arr;
    }
};

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}