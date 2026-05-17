#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
private:
    Node *front, *rear;

public:
    Queue(){
        front = rear = NULL;
    }
    bool isEmpty(){
        return (front == NULL);
    }
    void enqueue(int x){
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        if(rear == NULL) front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Elemen " << x << " masuk ke queue\n";
    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue kosong\n";
            return;
        }
        Node* temp = front;
        cout << "Elemen " << temp->data << " keluar dari queue\n";
        front = front->next;
        if(front == NULL) rear = NULL;
        delete temp;
    }
    void display(){
        if(isEmpty()){
            cout << "Queue kosong\n";
            return;
        }
        Node* temp = front;
        cout << "Isi Queue: ";
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}