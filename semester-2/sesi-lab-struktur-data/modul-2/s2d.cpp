#include <bits/stdc++.h>
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
    BSTNode* createNode(int value){
        BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
        node->key = value;
        node->left = node->right = NULL;
        return node;
    }
    BSTNode* insertNode(BSTNode *root, int value){
        if(root == NULL) return createNode(value);
        if(value < root->key) root->left = insertNode(root->left, value);
        else if(value > root->key) root->right = insertNode(root->right, value);
        return root;
    }
    void insert(int value){
        _root = insertNode(_root, value);
    }
    BSTNode* findParent(int value){
        BSTNode *curr = _root;
        BSTNode *parent = NULL;
        while(curr != NULL){
            if(value == curr->key) return parent;
            parent = curr;
            if(value < curr->key) curr = curr->left;
            else curr = curr->right;
        }
        return NULL;
    }
    void inorder(BSTNode *root, int target, int &cnt, int &ans){
        if(root == NULL) return;
        inorder(root->left, target, cnt, ans);
        cnt++;
        if(root->key == target){
            ans = cnt;
            return;
        }
        inorder(root->right, target, cnt, ans);
    }
    int getOrder(int value){
        int cnt = 0, ans = -1;
        inorder(_root, value, cnt, ans);
        return ans;
    }
};

int main(){
    BST bst;
    bst.init();
    int N;
    cin >> N;
    while(N--){
        string cmd;
        int x;
        cin >> cmd >> x;
        if(cmd == "Insert") bst.insert(x);
        else if(cmd == "Parent"){
            BSTNode* parent = bst.findParent(x);
            if(parent == NULL) cout << "Orphanage, here it comes" << endl;
            else cout << "Child of " << parent->key << endl;
        }
        else if(cmd == "Order"){
            int ans = bst.getOrder(x);
            cout << "Order : " << ans << "\n";
        }
    }
    return 0;
}