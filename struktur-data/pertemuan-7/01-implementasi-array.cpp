#include <bits/stdc++.h>
#define MAX 5
using namespace std;

class Queue{
private:
    int arr[MAX];
    int front, rear;

public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        return (front == -1);
    }
    bool isFull(){
        return (rear == MAX - 1);
    }
    void enqueue(int x){
        if(isFull()){
            cout << "Queue Overflow\n";
            return;
        }
        if(isEmpty()) front = 0;
        arr[++rear] = x;
        cout << "Elemen " << x << " masuk ke queue\n";
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Elemen " << arr[front] << " keluar dari queue\n";
        if(front == rear) front = rear = -1;
        else front++;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue kosong\n";
            return;
        }
        cout << "Isi Queue: ";
        for(int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}