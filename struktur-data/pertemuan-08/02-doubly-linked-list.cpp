#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

Node *insert(Node *node, int val){
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(node == NULL) return newNode;
    Node *temp = node;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return node;
}

void forward(Node *node){
    Node *temp = node;
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void backward(Node *node){
    if(node == NULL) return;
    Node *temp = node;
    while(temp->next != NULL) temp = temp->next;
    while(temp != NULL){
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* node = NULL;
    int n;
    cout << "Banyak data: ";
    cin >> n;
    while(n--){
        int x;
        cout << "Masukkan data: ";
        cin >> x;
        node = insert(node, x);
    }
    cout << endl << "Visualisasi:" << endl;
    cout << "Forward: ";
    forward(node);
    cout << "Backward: ";
    backward(node);
    return 0;
}