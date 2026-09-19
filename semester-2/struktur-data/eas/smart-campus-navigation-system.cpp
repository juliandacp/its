#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Hash Table (Login)
struct Mahasiswa{
    string nim;
    string nama;
    string prodi;
    int semester;
    string password;
};

unordered_map<string, Mahasiswa> akun_mahasiswa;

// Linked List (Riwayat)
list<string> riwayat_aktivitas;

// Queue (Antrian Konsultasi)
struct Konsultasi {
    string nim;
    string nama;
    string dosen;
};

queue<Konsultasi> antrian_konsultasi;

// Tree (Struktur Organisasi)
struct TreeNode{
    string nama;
    vector<TreeNode*> child;
    TreeNode(string n){
        nama = n;
    }
};

void tampil_tree(TreeNode* root, int level = 0){
    for(int i = 0; i < level; i++) cout << "   ";
    cout << "- " << root->nama << endl;
    for(auto c : root->child) tampil_tree(c, level + 1);
}

// Graph (Navigasi Kampus)
const int V = 5;
string lokasi_kampus[V] = {"Gerbang Utama", "Fakultas Teknik", "Perpustakaan", "Kantin", "Rektorat"};
vector<pair<int,int>> graph_kampus[V];

void tambah_jalan(int u, int v, int w){
    graph_kampus[u].push_back({v,w});
    graph_kampus[v].push_back({u,w});
}

void dijkstra(int start){
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : graph_kampus[u]){
            int v = edge.first;
            int w = edge.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << endl << "Rute dari " << lokasi_kampus[start] << endl;

    for(int i = 0; i < V; i++){
        cout << lokasi_kampus[i] << " = ";
        cout << dist[i] << endl;
    }
}

// Stack (Undo KRS)
struct MataKuliah{
    string kode;
    string nama;
};

stack<MataKuliah> stack_krs;

void tampil_krs(){
    stack<MataKuliah> temp = stack_krs;
    vector<MataKuliah> data;

    while(!temp.empty()){
        data.push_back(temp.top());
        temp.pop();
    }

    cout << endl << "Daftar Mata Kuliah:" << endl;

    for(int i = data.size() - 1; i >= 0; i--) cout << data[i].kode << " - " << data[i].nama << endl;
}

// Priority Queue
struct Layanan{
    int prioritas;
    string nama;

    bool operator<(const Layanan& other) const{
        return prioritas > other.prioritas;
    }
};

priority_queue<Layanan> layanan_prioritas;

// Menu

void registrasi(){
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

    akun_mahasiswa[m.nim] = m;

    cout << endl << "Registrasi berhasil!" << endl;
}

void login(){
    string nim, pw;

    cout << "NIM      : ";
    cin >> nim;

    cout << "Password : ";
    cin >> pw;

    if(akun_mahasiswa.count(nim) && akun_mahasiswa[nim].password == pw){
        cout << endl << "Login berhasil" << endl;
        riwayat_aktivitas.push_back("Login oleh " + akun_mahasiswa[nim].nama);
    }else cout << endl << "Login gagal" << endl;
}

void cari_akun(){
    string nim;

    cout << "Masukkan NIM : ";
    cin >> nim;

    if(akun_mahasiswa.count(nim)){
        cout << endl << "Nama : " << akun_mahasiswa[nim].nama << endl;
        cout << "Prodi : " << akun_mahasiswa[nim].prodi << endl;
    }else cout << "Data tidak ditemukan" << endl;
}

void tambah_riwayat(){
    string aktivitas;

    cin.ignore();

    cout << "Aktivitas : ";
    getline(cin, aktivitas);

    riwayat_aktivitas.push_back(aktivitas);
}

void tampil_riwayat(){
    cout << endl << "=== RIWAYAT ===" << endl;

    for(auto x : riwayat_aktivitas) cout << x << endl;
}

void ambil_antrian(){
    Konsultasi k;

    cin.ignore();

    cout << "Nama  : ";
    getline(cin, k.nama);

    cout << "NIM   : ";
    getline(cin, k.nim);

    cout << "Dosen : ";
    getline(cin, k.dosen);

    antrian_konsultasi.push(k);

    cout << "Berhasil masuk antrian" << endl;
}

void layani_antrian(){
    if(antrian_konsultasi.empty()){
        cout << "Tidak ada antrian\n";
        return;
    }

    Konsultasi k = antrian_konsultasi.front();
    antrian_konsultasi.pop();

    cout << endl << "Dilayani:" << endl;
    cout << k.nama << " - " << k.dosen << endl;
}

void tambah_mk(){
    MataKuliah mk;

    cin.ignore();

    cout << "Kode MK : ";
    getline(cin, mk.kode);

    cout << "Nama MK : ";
    getline(cin, mk.nama);

    stack_krs.push(mk);

    cout << "Mata kuliah ditambahkan" << endl;
}

void undo_mk(){
    if(stack_krs.empty()){
        cout << "Tidak ada data" << endl;
        return;
    }

    cout << "Undo: " << stack_krs.top().kode << " - " << stack_krs.top().nama << endl;

    stack_krs.pop();
}

void tambah_prioritas(){
    Layanan l;

    cin.ignore();

    cout << "Nama Mahasiswa : ";
    getline(cin, l.nama);

    cout << "Prioritas (1 tertinggi): ";
    cin >> l.prioritas;

    layanan_prioritas.push(l);
}

void layani_prioritas(){
    if(layanan_prioritas.empty()){
        cout << "Tidak ada layanan\n";
        return;
    }

    auto x = layanan_prioritas.top();
    layanan_prioritas.pop();

    cout << endl << "Dilayani : " << x.nama << " (Prioritas " << x.prioritas << ")" << endl;
}

int main(){
    // Struktur Organisasi ITS
    TreeNode* rektor = new TreeNode("Rektor");
    TreeNode* wr_akademik = new TreeNode("WR Akademik");
    TreeNode* wr_kemahasiswaan = new TreeNode("WR Kemahasiswaan");

    // Fakultas
    TreeNode* fteic = new TreeNode("Fakultas Teknologi Elektro dan Informatika Cerdas");
    TreeNode* fsad = new TreeNode("Fakultas Sains dan Analitika Data");
    TreeNode* ftirs = new TreeNode("Fakultas Teknologi Industri dan Rekayasa Sistem");
    TreeNode* ftspk = new TreeNode("Fakultas Teknik Sipil, Perencanaan, dan Kebumian");
    TreeNode* ftk = new TreeNode("Fakultas Teknologi Kelautan");
    TreeNode* fkbd = new TreeNode("Fakultas Desain Kreatif dan Bisnis Digital");
    TreeNode* vokasi = new TreeNode("Fakultas Vokasi");
    TreeNode* fkk = new TreeNode("Fakultas Kedokteran dan Kesehatan");

    // Hubungan Tree
    rektor->child.push_back(wr_akademik);
    rektor->child.push_back(wr_kemahasiswaan);

    wr_akademik->child.push_back(fteic);
    wr_akademik->child.push_back(fsad);
    wr_akademik->child.push_back(ftirs);
    wr_akademik->child.push_back(ftspk);
    wr_akademik->child.push_back(ftk);
    wr_akademik->child.push_back(fkbd);
    wr_akademik->child.push_back(vokasi);
    wr_akademik->child.push_back(fkk);

    // Graph Kampus
    tambah_jalan(0,1,2);
    tambah_jalan(0,2,4);
    tambah_jalan(1,2,1);
    tambah_jalan(1,3,7);
    tambah_jalan(2,4,3);
    tambah_jalan(4,3,2);

    int pilih;

    do{
        cout << endl << "=================================" << endl;
        cout << "SMART CAMPUS NAVIGATION SYSTEM" << endl;
        cout << "=================================" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Login" << endl;
        cout << "3. Cari Akun" << endl;
        cout << "4. Tambah Riwayat" << endl;
        cout << "5. Tampil Riwayat" << endl;
        cout << "6. Ambil Antrian Konsultasi" << endl;
        cout << "7. Layani Antrian" << endl;
        cout << "8. Tampil Struktur Organisasi" << endl;
        cout << "9. Navigasi Kampus (Dijkstra)" << endl;
        cout << "10. Tambah KRS" << endl;
        cout << "11. Undo KRS" << endl;
        cout << "12. Tampil KRS" << endl;
        cout << "13. Tambah Prioritas Layanan" << endl;
        cout << "14. Layani Prioritas" << endl;
        cout << "0. Keluar" << endl;
        cout << endl << "Pilih : ";

        cin >> pilih;

        switch(pilih){
        case 1:
            registrasi();
            break;

        case 2:
            login();
            break;

        case 3:
            cari_akun();
            break;

        case 4:
            tambah_riwayat();
            break;

        case 5:
            tampil_riwayat();
            break;

        case 6:
            ambil_antrian();
            break;

        case 7:
            layani_antrian();
            break;

        case 8:
            cout << endl << "=== STRUKTUR ORGANISASI ===" << endl;
            tampil_tree(rektor);
            break;

        case 9:
            dijkstra(0);
            break;

        case 10:
            tambah_mk();
            break;

        case 11:
            undo_mk();
            break;

        case 12:
            tampil_krs();
            break;

        case 13:
            tambah_prioritas();
            break;

        case 14:
            layani_prioritas();
            break;
        }

    }while(pilih != 0);
    return 0;
}