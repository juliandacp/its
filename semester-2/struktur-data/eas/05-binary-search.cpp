#include <iostream>
using namespace std;

struct Node {
    int nim;
    Node *left, *right;

    Node(int x) {
        nim = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int nim) {
    if(root == NULL)
        return new Node(nim);

    if(nim < root->nim)
        root->left = insert(root->left, nim);
    else
        root->right = insert(root->right, nim);

    return root;
}

bool search(Node* root, int nim) {
    if(root == NULL)
        return false;

    if(root->nim == nim)
        return true;

    if(nim < root->nim)
        return search(root->left, nim);

    return search(root->right, nim);
}

int main() {
    Node* root = NULL;

    root = insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);

    cout << search(root,40);
}