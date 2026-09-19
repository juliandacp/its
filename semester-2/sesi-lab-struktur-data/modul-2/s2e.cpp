#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct AVLNode{
    int data;
    AVLNode *left, *right;
    int height;
};

struct AVL{
    AVLNode *_root;
    unsigned _size;
    map<int, ll> mp;
    AVLNode* _avl_createNode(int value){
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    AVLNode* _search(AVLNode *root, int value){
        while(root != NULL){
            if(value < root->data) root = root->left;
            else if(value > root->data) root = root->right;
            else return root;
        }
        return root;
    }
    int _getHeight(AVLNode* node){
        if(node==NULL) return 0; 
        return node->height;
    }
    int _max(int a,int b){
        if(a > b) return a;
        else return b;
    }
    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;
        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;
        return newParrent;
    }
    AVLNode* _leftRotate(AVLNode* pivotNode){
        AVLNode* newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;
        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;
        return newParrent;
    }
    AVLNode* _leftRightCaseRotate(AVLNode* node){
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }
    AVLNode* _rightLeftCaseRotate(AVLNode* node){
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }
    int _getBalanceFactor(AVLNode* node){
        if(node==NULL) return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }
    AVLNode* _insert_AVL(AVLNode* node,int value) {
        if(node==NULL) return _avl_createNode(value);
        if(value < node->data) node->left = _insert_AVL(node->left,value);
        else if(value > node->data) node->right = _insert_AVL(node->right,value);
        node->height = 1 + _max(_getHeight(node->left),_getHeight(node->right));
        int balanceFactor = _getBalanceFactor(node);
        if(balanceFactor > 1 && value < node->left->data) return _rightRotate(node);
        if(balanceFactor > 1 && value > node->left->data) return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && value > node->right->data) return _leftRotate(node);
        if(balanceFactor < -1 && value < node->right->data) return _rightLeftCaseRotate(node);
        return node;
    }
    void _inorderHD(AVLNode* node, int hd){
        if(node){
            _inorderHD(node->left, hd - 1);
            mp[hd] += node->data;
            _inorderHD(node->right, hd + 1);
        }
    }
    ll getPassword(){
        mp.clear();
        _inorderHD(_root, 0);
        ll res = 0;
        for(auto x : mp) res += x.second * x.second;
        return res;
    }
    void init(){
        _root = NULL;
        _size = 0U;
    }
    bool find(int value){
        AVLNode *temp = _search(_root, value);
        return temp != NULL && temp->data == value;
    }
    void insert(int value){
        if (!find(value)){
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }
};

int main(){
    AVL tree;
    tree.init();
    string cmd;
    while(cin >> cmd){
        if(cmd == "Insert"){
            int x;
            cin >> x;
            tree.insert(x);
        }
        else if(cmd == "Password"){
            cout << tree.getPassword() << endl;
        }
    }
    return 0;
}