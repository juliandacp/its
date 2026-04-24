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
    bool imbalance;
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
        if(balanceFactor > 1 || balanceFactor < -1) imbalance = true;
        if(balanceFactor > 1 && value < node->left->data) return _rightRotate(node);
        if(balanceFactor > 1 && value > node->left->data) return _leftRightCaseRotate(node);
        if(balanceFactor < -1 && value > node->right->data) return _leftRotate(node);
        if(balanceFactor < -1 && value < node->right->data) return _rightLeftCaseRotate(node);
        return node;
    }
    void _inorder(AVLNode *node){
        if(node){
            _inorder(node->left);
            cout << node->data << " ";
            _inorder(node->right);
        }
    }
    void init(){
        _root = NULL;
        _size = 0U;
        imbalance = false;
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
    void inorder(){
        _inorder(_root);
    }
};

int main(){
    string name;
    while(getline(cin, name)){
        if(name == "") continue;
        int n;
        cin >> n;
        AVL tree;
        tree.init();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            tree.insert(x);
        }
        cin.ignore();
        if(tree.imbalance) cout << name << " is suspicious, hang this person now!" << endl;
        else{
            cout << name << " is innocent." << endl;
            tree.inorder();
            cout << endl;
        }
    }
    return 0;
}