#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;

    Node(char val){
        data = val;
        left = right = NULL;
    }
};

void preorder(Node* root){
    if (root == NULL) return;
    cout << root->data << " "; // Root
    preorder(root->left); // Left
    preorder(root->right); // Right
}

void inorder(Node* root){
    if (root == NULL) return;
    inorder(root->left); // Left
    cout << root->data << " "; // Root
    inorder(root->right); // Right
}

void postorder(Node* root){
    if (root == NULL) return;
    postorder(root->left); // Left
    postorder(root->right); // Right
    cout << root->data << " "; // Root
}

void levelOrder(Node* root){
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
    }
}

int main(){
    // Membuat Tree
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    cout << "Preorder : ";
    preorder(root);
    cout << "\nInorder : ";
    inorder(root);
    cout << "\nPostorder : ";
    postorder(root);
    cout << "\nLevelOrder: ";
    levelOrder(root);

    return 0;
}