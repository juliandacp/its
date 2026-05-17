#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// CLASS NODE
class Node{
public:
    string name;
    Node* parent;
    vector<Node*> children;

    // Constructor
    Node(string folderName, Node* p = NULL){
        name = folderName;
        parent = p;
    }
};

// CLASS GENERAL TREE
class FolderTree{
private:
    Node* root;

public:
    // Constructor
    FolderTree(){
        root = new Node("Root");
    }
    
    // GET ROOT
    Node* getRoot(){
        return root;
    }

    // MENAMBAH FOLDER
    void addFolder(Node* parent, string folderName){
        Node* newFolder = new Node(folderName, parent);
        parent->children.push_back(newFolder);
        cout << "Folder '" << folderName << "' berhasil ditambahkan ke '" << parent->name << "'\n";
    }

    // MENAMPILKAN TREE
    void printTree(Node* node, string prefix = "", bool isLast = true){
        if(node == NULL) return;

        // Root
        if(node == root) cout << node->name << endl;
        else{
            cout << prefix;
            cout << (isLast ? "└── " : "├── ");
            cout << node->name << endl;
        }

        // Prefix Baru
        string newPrefix;
        if(node == root) newPrefix = "";
        else newPrefix = prefix + (isLast ? "    " : "│   ");

        // Rekursif Child
        for(size_t i = 0; i < node->children.size(); i++){
            bool lastChild = (i == node->children.size() - 1);
            printTree(node->children[i], newPrefix, lastChild);
        }
    }
    
    // PREORDER TRAVERSAL
    void preorder(Node* node){
        if(node == NULL) return;
        cout << node->name << endl;
        for(Node* child : node->children) preorder(child);
    }

    // POSTORDER TRAVERSAL
    void postorder(Node* node){
        if(node == NULL) return;
        for(Node* child : node->children) postorder(child);
        cout << node->name << endl;
    }

    // SEARCH FOLDER
    Node* search(Node* node, string target){
        if(node == NULL) return NULL;

        // Jika ditemukan
        if(node->name == target) return node;

        // Cari di child
        for(Node* child : node->children){
            Node* result = search(child, target);
            if(result != NULL) return result;
        }
        return NULL;
    }

    // HITUNG JUMLAH FOLDER
    int countFolder(Node* node){
        if(node == NULL) return 0;
        int total = 1;
        for(Node* child : node->children) total += countFolder(child);
        return total;
    }

    // MENAMPILKAN PATH
    void showPath(Node* node){
        if(node == NULL) return;
        vector<string> path;
        Node* current = node;
        while(current != NULL){
            path.push_back(current->name);
            current = current->parent;
        }
        cout << "Path : ";
        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i];
            if(i != 0) cout << "/";
        }
        cout << endl;
    }

    // DELETE SUBTREE
    void deleteSubtree(Node* node){
        if(node == NULL) return;

        // Hapus child dulu
        for(Node* child : node->children) deleteSubtree(child);
        delete node;
    }

    // HAPUS FOLDER
    void deleteFolder(string folderName){
        Node* target = search(root, folderName);
        if(target == NULL){
            cout << "Folder tidak ditemukan!\n";
            return;
        }

        // Root tidak boleh dihapus
        if(target == root){
            cout << "Root tidak dapat dihapus!\n";
            return;
        }
        Node* parent = target->parent;

        // Hapus dari vector child parent
        for(auto it = parent->children.begin(); it != parent->children.end(); it++){
            if(*it == target){
                parent->children.erase(it);
                break;
            }
        }

        // Hapus subtree
        deleteSubtree(target);
        cout << "Folder berhasil dihapus!\n";
    }
};

// MAIN PROGRAM
int main() {

    // Agar simbol Unicode tampil benar
    SetConsoleOutputCP(CP_UTF8);

    FolderTree tree;

    // Root
    Node* root = tree.getRoot();

    // MEMBUAT STRUKTUR FOLDER
    tree.addFolder(root, "Documents");
    tree.addFolder(root, "Pictures");
    tree.addFolder(root, "Music");

    // Cari Documents
    Node* documents = tree.search(root, "Documents");

    // Tambah child Documents
    tree.addFolder(documents, "Kuliah");
    tree.addFolder(documents, "Tugas");

    // TAMPILKAN TREE
    cout << "\n===== STRUKTUR FOLDER =====\n";
    tree.printTree(root);

    // PREORDER
    cout << "\n===== PREORDER TRAVERSAL =====\n";
    tree.preorder(root);

    // POSTORDER
    cout << "\n===== POSTORDER TRAVERSAL =====\n";
    tree.postorder(root);

    // SEARCH
    cout << "\n===== SEARCH FOLDER =====\n";
    Node* result = tree.search(root, "Tugas");
    if(result != NULL){
        cout << "Folder ditemukan : " << result->name << endl;
        tree.showPath(result);
    }
    else cout << "Folder tidak ditemukan\n";

    // COUNT FOLDER
    cout << "\n===== JUMLAH FOLDER =====\n";
    cout << "Total Folder : " << tree.countFolder(root) << endl;

    // DELETE FOLDER
    cout << "\n===== HAPUS FOLDER =====\n";
    tree.deleteFolder("Pictures");

    // TAMPILKAN TREE SETELAH DELETE
    cout << "\n===== STRUKTUR SETELAH DELETE =====\n";
    tree.printTree(root);
    return 0;
}