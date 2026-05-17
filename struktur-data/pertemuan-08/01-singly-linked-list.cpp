#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *insert(Node *node, int val){
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if(node == NULL) return newNode;
    Node *temp = node;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return node;
}

void traversal(Node *node){
    if(node == NULL) return;
    Node *temp = node;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main(){
    Node *node = NULL;
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
    traversal(node);
    return 0;
}