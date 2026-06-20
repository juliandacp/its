#include <bits/stdc++.h>
#define ll long long
using namespace std;

/* ==========================
   HASH TABLE (LOGIN)
   ========================== */
struct Mahasiswa {
    string nim;
    string nama;
    string prodi;
    int semester;
    string password;
};

unordered_map<string, Mahasiswa> akun;

/* ==========================
   LINKED LIST (RIWAYAT)
   ========================== */
list<string> riwayat;

/* ==========================
   QUEUE (ANTRIAN KONSULTASI)
   ========================== */
struct Konsultasi {
    string nim;
    string nama;
    string dosen;
};

queue<Konsultasi> antrianKonsultasi;

/* ==========================
   TREE (STRUKTUR ORGANISASI)
   ========================== */
struct TreeNode {
    string nama;
    vector<TreeNode*> child;

    TreeNode(string n) {
        nama = n;
    }
};

void tampilTree(TreeNode* root, int level = 0) {
    for(int i=0;i<level;i++) cout << "   ";
    cout << "- " << root->nama << endl;

    for(auto c : root->child)
        tampilTree(c, level + 1);
}

/* ==========================
   GRAPH (NAVIGASI KAMPUS)
   ========================== */
const int V = 5;
string lokasi[V] = {
    "Gerbang Utama",
    "Fakultas Teknik",
    "Perpustakaan",
    "Kantin",
    "Rektorat"
};

vector<pair<int,int>> graph[V];

void tambahJalan(int u, int v, int w){
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
}

void dijkstra(int start){
    vector<int> dist(V, INT_MAX);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : graph[u]){
            int v = edge.first;
            int w = edge.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nRute dari " << lokasi[start] << endl;
    for(int i=0;i<V;i++){
        cout << lokasi[i] << " = ";
        cout << dist[i] << endl;
    }
}

/* ==========================
   STACK (UNDO KRS)
   ========================== */
stack<string> krs;

void tampilKRS() {
    stack<string> temp = krs;

    vector<string> data;

    while(!temp.empty()){
        data.push_back(temp.top());
        temp.pop();
    }

    cout << "\nDaftar Mata Kuliah:\n";

    for(int i=data.size()-1;i>=0;i--)
        cout << data[i] << endl;
}

/* ==========================
   PRIORITY QUEUE
   ========================== */
struct Layanan {
    int prioritas;
    string nama;

    bool operator<(const Layanan& other) const {
        return prioritas > other.prioritas;
    }
};

priority_queue<Layanan> layanan;

/* ==========================
   MENU
   ========================== */

void registrasi() {
    Mahasiswa m;

    cout << "NIM      : ";
    cin >> m.nim;

    cin.ignore();

    cout << "Nama     : ";
    getline(cin,m.nama);

    cout << "Prodi    : ";
    getline(cin,m.prodi);

    cout << "Semester : ";
    cin >> m.semester;

    cout << "Password : ";
    cin >> m.password;

    akun[m.nim] = m;

    cout << "\nRegistrasi berhasil!\n";
}

void login() {
    string nim, pass;

    cout << "NIM      : ";
    cin >> nim;

    cout << "Password : ";
    cin >> pass;

    if(akun.count(nim) && akun[nim].password == pass){
        cout << "\nLogin berhasil\n";

        riwayat.push_back("Login oleh " + akun[nim].nama);
    }
    else{
        cout << "\nLogin gagal\n";
    }
}

void cariAkun() {
    string nim;

    cout << "Masukkan NIM : ";
    cin >> nim;

    if(akun.count(nim)){
        cout << "\nNama : "
             << akun[nim].nama << endl;

        cout << "Prodi : "
             << akun[nim].prodi << endl;
    }
    else{
        cout << "Data tidak ditemukan\n";
    }
}

void tambahRiwayat() {
    string aktivitas;

    cin.ignore();

    cout << "Aktivitas : ";
    getline(cin, aktivitas);

    riwayat.push_back(aktivitas);
}

void tampilRiwayat() {
    cout << "\n=== RIWAYAT ===\n";

    for(auto x : riwayat)
        cout << x << endl;
}

void ambilAntrian() {
    Konsultasi k;

    cin.ignore();

    cout << "Nama  : ";
    getline(cin,k.nama);

    cout << "NIM   : ";
    getline(cin,k.nim);

    cout << "Dosen : ";
    getline(cin,k.dosen);

    antrianKonsultasi.push(k);

    cout << "Berhasil masuk antrian\n";
}

void layaniAntrian() {
    if(antrianKonsultasi.empty()){
        cout << "Tidak ada antrian\n";
        return;
    }

    Konsultasi k = antrianKonsultasi.front();
    antrianKonsultasi.pop();

    cout << "\nDilayani:\n";
    cout << k.nama << " - " << k.dosen << endl;
}

void tambahMK() {
    string mk;

    cin.ignore();

    cout << "Kode MK : ";
    getline(cin,mk);

    krs.push(mk);

    cout << "Mata kuliah ditambahkan\n";
}

void undoMK() {
    if(krs.empty()){
        cout << "Tidak ada data\n";
        return;
    }

    cout << "Undo: "
         << krs.top()
         << endl;

    krs.pop();
}

void tambahPrioritas() {
    Layanan l;

    cin.ignore();

    cout << "Nama Mahasiswa : ";
    getline(cin,l.nama);

    cout << "Prioritas (1 tertinggi): ";
    cin >> l.prioritas;

    layanan.push(l);
}

void layaniPrioritas() {
    if(layanan.empty()){
        cout << "Tidak ada layanan\n";
        return;
    }

    auto x = layanan.top();
    layanan.pop();

    cout << "\nDilayani : "
         << x.nama
         << " (Prioritas "
         << x.prioritas
         << ")\n";
}

int main() {

    /* Struktur Organisasi */
    TreeNode* rektor = new TreeNode("Rektor");

    TreeNode* wrAkademik =
        new TreeNode("WR Akademik");

    TreeNode* wrKemahasiswaan =
        new TreeNode("WR Kemahasiswaan");

    TreeNode* teknik =
        new TreeNode("Fakultas Teknik");

    TreeNode* ekonomi =
        new TreeNode("Fakultas Ekonomi");

    rektor->child.push_back(wrAkademik);
    rektor->child.push_back(wrKemahasiswaan);

    wrAkademik->child.push_back(teknik);
    wrAkademik->child.push_back(ekonomi);

    /* Graph Kampus */
    tambahJalan(0,1,2);
    tambahJalan(0,2,4);
    tambahJalan(1,2,1);
    tambahJalan(1,3,7);
    tambahJalan(2,4,3);
    tambahJalan(4,3,2);

    int pilih;

    do {
        cout << "\n=================================\n";
        cout << "SMART CAMPUS NAVIGATION SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Registrasi\n";
        cout << "2. Login\n";
        cout << "3. Cari Akun\n";
        cout << "4. Tambah Riwayat\n";
        cout << "5. Tampil Riwayat\n";
        cout << "6. Ambil Antrian Konsultasi\n";
        cout << "7. Layani Antrian\n";
        cout << "8. Tampil Struktur Organisasi\n";
        cout << "9. Navigasi Kampus (Dijkstra)\n";
        cout << "10. Tambah KRS\n";
        cout << "11. Undo KRS\n";
        cout << "12. Tampil KRS\n";
        cout << "13. Tambah Prioritas Layanan\n";
        cout << "14. Layani Prioritas\n";
        cout << "0. Keluar\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch(pilih){

        case 1:
            registrasi();
            break;

        case 2:
            login();
            break;

        case 3:
            cariAkun();
            break;

        case 4:
            tambahRiwayat();
            break;

        case 5:
            tampilRiwayat();
            break;

        case 6:
            ambilAntrian();
            break;

        case 7:
            layaniAntrian();
            break;

        case 8:
            cout << "\n=== STRUKTUR ORGANISASI ===\n";
            tampilTree(rektor);
            break;

        case 9:
            dijkstra(0);
            break;

        case 10:
            tambahMK();
            break;

        case 11:
            undoMK();
            break;

        case 12:
            tampilKRS();
            break;

        case 13:
            tambahPrioritas();
            break;

        case 14:
            layaniPrioritas();
            break;
        }

    } while(pilih != 0);

    return 0;
}