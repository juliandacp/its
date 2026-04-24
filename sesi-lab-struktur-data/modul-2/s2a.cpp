#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct BSTNode{
    int key;
    BSTNode *left, *right;
};

struct BST{
    BSTNode *_root;
    unsigned int _size;
    void init(){
        _root = NULL;
        _size = 0;
    }
    bool isEmpty(){
        return _root == NULL;
    }
    BSTNode* createNode(int value){
        BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
        node->key = value;
        node->left = node->right = NULL;
        return node;
    }
    BSTNode* search(BSTNode *root, int value){
        while(root != NULL){
            if(value < root->key) root = root->left;
            else if(value > root->key) root = root->right;
            else return root;
        }
        return NULL;
    }
    BSTNode* insertNode(BSTNode *root, int value){
        if(root == NULL){
            BSTNode* node = createNode(value);
            return node;
        }
        if(value < root->key) root->left = insertNode(root->left, value);
        else if(value > root->key) root->right = insertNode(root->right, value);
        return root;
    }
    bool find(int value){
        BSTNode *temp = search(_root, value);
        return temp != NULL && temp->key == value;
    }
    void insert(int value){
        if(!find(value)){
            _root = insertNode(_root, value);
            _size++;
        }
    }
    BSTNode* findNode(int value) {
        return search(_root, value);
    }
    int maxDepth(BSTNode *root){
        if (root == NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int res;
        if(left > right) res = left;
        else res = right;
        return 1 + res;
    }
};

int main() {
    BST bst;
    bst.init();
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        bst.insert(x);
    }
    int M;
    cin >> M;
    BSTNode* start = bst.findNode(M);
    int depth = bst.maxDepth(start) - 1;
    long long gaji = 10000 * depth * depth;
    cout << gaji << endl;
    return 0;
}