#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Tree{
    map<string, vector<string>> nodes;
};

// Menambahkan child ke parent
void insertNode(Tree& tree, const string& parent, const string& child){
    tree.nodes[parent].push_back(child);
}

// Mencetak tree dengan garis
void cetak_tree(Tree& tree, const string& nama, const string& prefix,
                bool is_last, bool is_root = false){

    if(is_root)
        cout << nama << endl;
    else
        cout << prefix << (is_last ? "|___ " : "|-- ") << nama << endl;

    auto it = tree.nodes.find(nama);

    if(it == tree.nodes.end() || it->second.empty())
        return;

    string newPrefix = prefix;

    if(!is_root)
        newPrefix += (is_last ? "    " : "|   ");

    auto& children = it->second;

    for(size_t i = 0; i < children.size(); i++){
        bool last = (i == children.size() - 1);
        cetak_tree(tree, children[i], newPrefix, last);
    }
}

int main(){

    Tree folder;

    insertNode(folder, "Root", "Dokumen");
    insertNode(folder, "Root", "Gambar");

    insertNode(folder, "Dokumen", "Tugas");
    insertNode(folder, "Dokumen", "Skripsi");

    insertNode(folder, "Gambar", "Foto");
    insertNode(folder, "Gambar", "Logo");

    cout << "Struktur Folder:\n\n";

    cetak_tree(folder, "Root", "", true, true);

    return 0;
}