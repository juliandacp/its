#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

struct BST {
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = NULL;
        _size = 0;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        return __search(_root, value) != NULL;
    }

    void insert(int value) {
        _root = __insert(_root, value);
        _size++;
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

    int getMin() {
        BSTNode *curr = _root;
        while(curr->left)
            curr = curr->left;
        return curr->key;
    }

    int getMax() {
        BSTNode *curr = _root;
        while(curr->right)
            curr = curr->right;
        return curr->key;
    }

    int getHeight() {
        return __height(_root);
    }

    BSTNode* __createNode(int value) {
        BSTNode *newNode = new BSTNode();
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    BSTNode* __search(BSTNode *root, int value) {
        while(root != NULL) {
            if(value < root->key)
                root = root->left;
            else if(value > root->key)
                root = root->right;
            else
                return root;
        }
        return NULL;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if(root == NULL)
            return __createNode(value);

        if(value < root->key)
            root->left = __insert(root->left, value);
        else
            root->right = __insert(root->right, value);

        return root;
    }

    void __inorder(BSTNode *root) {
        if(root) {
            __inorder(root->left);
            cout << root->key << " ";
            __inorder(root->right);
        }
    }

    void __preorder(BSTNode *root) {
        if(root) {
            cout << root->key << " ";
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if(root) {
            __postorder(root->left);
            __postorder(root->right);
            cout << root->key << " ";
        }
    }

    int __height(BSTNode *root) {
        if(root == NULL) return 0;
        return 1 + max(__height(root->left), __height(root->right));
    }
};

int main(){
    BST tree;
    tree.init();
    map<int, int> freq;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        tree.insert(x);
        freq[x]++;
    }
    int X;
    cin >> X;
    cout << "Inorder Traversal: ";
    tree.traverseInorder();
    cout << endl;
    cout << "Preorder Traversal: ";
    tree.traversePreorder();
    cout << endl;
    cout << "Postorder Traversal: ";
    tree.traversePostorder();
    cout << endl;
    cout << "Minimum Value: " << tree.getMin() << endl;
    cout << "Maximum Value: " << tree.getMax() << endl;
    cout << "Height: " << tree.getHeight() << endl;
    if(tree.find(X)) cout << "Search " << X << ": FOUND" << endl;
    else cout << "Search " << X << ": NOT FOUND" << endl;
    cout << "Frequency of " << X << ": " << freq[X] << endl;
    return 0;
}