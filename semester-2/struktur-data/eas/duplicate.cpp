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
    int id;
    string nim;
    string nama;
    string dosen;
    string waktu;
};

queue<Konsultasi> antrian_konsultasi;

// Tree (Struktur Organisasi)
struct Tree {
    string root;
    unordered_map<string, vector<string>> nodes;
};

Tree struktur_organisasi;

// Graph (Navigasi Kampus)
unordered_map<string, vector<pair<string,int>>> graph_kampus;

// Stack (Undo KRS)
stack<string> stack_krs;

// Priority Queue
struct Layanan{
    int prioritas;
    string nama;
    bool operator<(const Layanan& other) const{
        return prioritas < other.prioritas;
    }
};

priority_queue<Layanan> layanan_prioritas;

// Login State
bool sudah_login = false;
Mahasiswa mahasiswa_aktif;

// Helper Tree
bool node_ada(Tree& tree, const string& nama){
    if(tree.root == nama) return true;
    if(tree.nodes.find(nama) != tree.nodes.end()) return true;
    for(auto& p : tree.nodes)
        for(auto& c : p.second)
            if(c == nama) return true;
    return false;
}

void hapus_subtree(Tree& tree, const string& nama){
    if(tree.nodes.find(nama) != tree.nodes.end()){
        vector<string> anak = tree.nodes[nama];
        for(auto& c : anak) hapus_subtree(tree, c);
        tree.nodes.erase(nama);
    }
}

void cetak_tree(Tree& tree, const string& nama, const string& prefix, bool isLast, bool is_root = false){
    if(is_root) cout << nama << endl;
    else cout << prefix << (isLast ? "|___ " : "|-- ") << nama << endl;
    auto it = tree.nodes.find(nama);
    if(it == tree.nodes.end() || it->second.empty()) return;
    string newPrefix = prefix;
    if(!is_root) newPrefix += (isLast ? "    " : "|   ");
    auto& children = it->second;
    for(size_t i = 0; i < children.size(); i++){
        bool last = (i == children.size() - 1);
        cetak_tree(tree, children[i], newPrefix, last);
    }
}

// Mock Data
void mockdata(){
    akun_mahasiswa["budi123"] = {"001", "Budi Santoso", "Teknik Informatika", 3, "1234"};
    akun_mahasiswa["ani456"] = {"002", "Ani Rahayu", "Teknik Elektro", 5, "1234"};
    akun_mahasiswa["cici789"] = {"003", "Cici Lestari", "Matematika", 2, "1234"};

    graph_kampus["Gerbang Utama"] = {{"Fakultas Teknik", 2}, {"Rektorat", 3}};
    graph_kampus["Fakultas Teknik"] = {{"Gerbang Utama", 2}, {"Perpustakaan", 1}, {"Kantin", 3}};
    graph_kampus["Perpustakaan"] = {{"Fakultas Teknik", 1}, {"Rektorat", 2}, {"Lab Komputer", 3}};
    graph_kampus["Kantin"] = {{"Fakultas Teknik", 3}, {"Lab Komputer", 1}};
    graph_kampus["Rektorat"] = {{"Gerbang Utama", 3}, {"Perpustakaan", 2}};
    graph_kampus["Lab Komputer"] = {{"Perpustakaan", 3}, {"Kantin", 1}};

    struktur_organisasi.root = "Rektor";

    // Hubungkan Rektor ke Wakil Rektor (WR)
    struktur_organisasi.nodes["Rektor"].push_back("WR Akademik");
    struktur_organisasi.nodes["Rektor"].push_back("WR Kemahasiswaan");

    // Hubungkan WR Akademik ke Fakultas-Fakultas
    struktur_organisasi.nodes["WR Akademik"].push_back("FTEIC");
    struktur_organisasi.nodes["WR Akademik"].push_back("FSAD");
    struktur_organisasi.nodes["WR Akademik"].push_back("FTIRS");
    struktur_organisasi.nodes["WR Akademik"].push_back("FTSPK");
    struktur_organisasi.nodes["WR Akademik"].push_back("FTK");
    struktur_organisasi.nodes["WR Akademik"].push_back("FKBD");
    struktur_organisasi.nodes["WR Akademik"].push_back("Vokasi");
    struktur_organisasi.nodes["WR Akademik"].push_back("FKK");
}

// Tampil Konsultasi
void tampil_konsultasi(Konsultasi k){
    cout << endl;
    cout << "ID    : " << k.id << endl;
    cout << "Nama  : " << k.nama << endl;
    cout << "NIM   : " << k.nim << endl;
    cout << "Dosen : " << k.dosen << endl;
    cout << "Waktu : " << k.waktu << endl;
    cout << endl;
}

// Riwayat
void riwayat(){
    int opsi = 0;
    while(opsi != 4){
        cout << "=================" << endl;
        cout << "Riwayat Aktivitas" << endl;
        cout << "=================" << endl << endl;
        cout << "1. Hapus riwayat terakhir" << endl;
        cout << "2. Hapus semua riwayat" << endl;
        cout << "3. Tampilkan semua riwayat" << endl;
        cout << "4. Kembali" << endl << endl;
        cout << "Pilih Opsi: ";
        cout << endl;
        cin >> opsi;
        if(opsi == 1){
            if(!riwayat_aktivitas.empty()){
                riwayat_aktivitas.pop_back();
                cout << "Riwayat berhasil dihapus!" << endl;
            }else cout << "Riwayat sudah kosong!" << endl;
        }else if(opsi == 2){
            riwayat_aktivitas.clear();
            cout << "Riwayat berhasil dihapus!" << endl;
        }else if(opsi == 3){
            if(riwayat_aktivitas.empty()) cout << "(Belum ada riwayat aktivitas)" << endl;
            else{
                for(const auto& x : riwayat_aktivitas) cout << x << " -> ";
                cout << "End of List" << endl;
            }
        }
    }
}

// Antrian Konsultasi
void antrian(){
    cout << "===================================" << endl;
    cout << "\tAntrian Konsultasi" << endl;
    cout << "===================================" << endl << endl;
    int opsi;
    while(true){
        cout << "1. Tambahkan Jadwal Konsultasi" << endl;
        cout << "2. Layani Antrian (Hapus paling depan)" << endl;
        cout << "3. Lihat Antrian depan" << endl;
        cout << "4. Kembali" << endl << endl;
        cout << "Pilih Opsi: ";
        cin >> opsi;
        cout << endl;
        if(opsi == 4){
            return;
        }else if(opsi == 3){
            if(!antrian_konsultasi.empty()){
                tampil_konsultasi(antrian_konsultasi.front());
            }else{
                cout << "Antrian konsultasi kosong!" << endl;
            }
        }else if(opsi == 2){
            if(!antrian_konsultasi.empty()){
                cout << "Melayani antrian paling depan";
                tampil_konsultasi(antrian_konsultasi.front());
                riwayat_aktivitas.push_back("Melayani Konsultasi: " + antrian_konsultasi.front().nama + " (NIM: " + antrian_konsultasi.front().nim + ")");
                antrian_konsultasi.pop();
                cout << "Penghapusan berhasil!" << endl;
            }else cout << "Antrian konsultasi kosong!" << endl;
        }else if(opsi == 1){
            Konsultasi k;
            k.id = antrian_konsultasi.size() + 1;
            
            cin.ignore();
            cout << "Masukkan nama: " << endl;
            getline(cin, k.nama); 
            
            cout << "Masukkan NIM: " << endl;
            cin >> k.nim; 
            
            cin.ignore(); 
            cout << "Masukkan nama dosen: " << endl;
            getline(cin, k.dosen); 
            
            cout << "Masukkan waktu: " << endl;
            getline(cin, k.waktu);
            
            antrian_konsultasi.push(k);
            riwayat_aktivitas.push_back("Menambahkan Konsultasi: " + k.nama + " (NIM: " + k.nim + ")");
            cout << "Konsultasi berhasil ditambahkan!" << endl << endl;
        }else cout << "Opsi tidak ditemukan!" << endl;
    }
}

// Struktur Organisasi
void struktur(){
    cout << "===================================" << endl;
    cout << "\tStruktur Organisasi Kampus" << endl;
    cout << "===================================" << endl << endl;
    int opsi;
    while(true){
        cout << "1. Tambahkan Jabatan" << endl;
        cout << "2. Hapus Jabatan" << endl;
        cout << "3. Tampilkan Struktur" << endl;
        cout << "4. Kembali" << endl << endl;
        cout << "Pilih Opsi: ";
        cin >> opsi;
        if(opsi == 4){
            return;
        }else if(opsi == 3){
            if(struktur_organisasi.root.empty()) cout << ">> Struktur masih kosong, root belum diset." << endl << endl;
            else{
                cout << endl;
                cetak_tree(struktur_organisasi, struktur_organisasi.root, "", true, true);
                cout << endl;
            }
        }else if(opsi == 2){
            string nama;
            cout << "Masukkan nama jabatan yang akan dihapus: ";
            cin.ignore();
            getline(cin, nama);
            if(nama == struktur_organisasi.root) struktur_organisasi.root.clear();
            for(auto& p : struktur_organisasi.nodes){
                auto& children = p.second;
                for(size_t i = 0; i < children.size(); i++){
                    if(children[i] == nama){
                        children.erase(children.begin() + i);
                        break;
                    }
                }
            }
            hapus_subtree(struktur_organisasi, nama);
            cout << "Berhasil menghapus \"" << nama << "\" beserta seluruh bawahannya (jika ada)." << endl << endl;
            riwayat_aktivitas.push_back("Menghapus Jabatan " + nama);
        }else if(opsi == 1){
            if(struktur_organisasi.root.empty()){
                string jabatan;
                cout << "Tree masih kosong. Masukkan nama jabatan tertinggi (root): ";
                cin.ignore();
                getline(cin, jabatan);
                struktur_organisasi.root = jabatan;
                cout << "Root berhasil diset ke " << struktur_organisasi.root << endl << endl;
                riwayat_aktivitas.push_back("Menambahkan Jabatan " + jabatan);
            }else{
                string parent, jabatanBaru;
                cout << "Masukkan nama atasan (parent): ";
                cin.ignore();
                getline(cin, parent);
                cout << "Masukkan nama jabatan baru: ";
                getline(cin, jabatanBaru);
                struktur_organisasi.nodes[parent].push_back(jabatanBaru);
                cout << "Berhasil menambahkan \"" << jabatanBaru << "\" di bawah \"" << parent << "\"." << endl << endl;
                riwayat_aktivitas.push_back("Menambahkan Jabatan " + jabatanBaru);
            }
        }else cout << "Opsi tidak ditemukan!" << endl;
    }
}

// Navigasi Kampus
void navigasi(){
    cout << "===================================" << endl;
    cout << "\tNavigasi Kampus (Graph)" << endl;
    cout << "===================================" << endl << endl;
    int opsi;
    while(true){
        cout << "1. Cari Rute Terpendek (Dijkstra)" << endl;
        cout << "2. Tampilkan Semua Lokasi & Jalur" << endl;
        cout << "3. Tambah Lokasi Baru (Vertex)" << endl;
        cout << "4. Tambah Jalur Baru (Edge)" << endl;
        cout << "5. Kembali" << endl << endl;
        cout << "Pilih Opsi: ";
        cin >> opsi;
        cout << endl;
        if(opsi == 5) return;
        else if(opsi == 2){
            cout << "--- Daftar Gedung dan Koneksi Jalan ---" << endl;
            for(auto const& [asal, list_tujuan] : graph_kampus){
                cout << asal << " terhubung ke:" << endl;
                for(auto const& tetangga : list_tujuan) cout << "  -> " << tetangga.first << " (Jarak: " << tetangga.second << ")" << endl;
            }
            cout << endl;
        }else if(opsi == 3){
            string new_vertex;
            cout << "Masukkan nama lokasi baru: ";
            cin.ignore(); 
            getline(cin, new_vertex);
            if(graph_kampus.find(new_vertex) == graph_kampus.end()){
                graph_kampus[new_vertex] = vector<pair<string,int>>();
                cout << "Lokasi \"" << new_vertex << "\" berhasil ditambahkan!" << endl << endl;
                riwayat_aktivitas.push_back("Menambahkan Vertex Navigasi: " + new_vertex);
            }else cout << "Lokasi sudah terdaftar!" << endl << endl;
        }else if(opsi == 4){
            }else if(opsi == 4){
                string asal, tujuan;
                int bobot;
                cout << "Masukkan Lokasi Asal: ";
                cin.ignore();
                getline(cin, asal);
                cout << "Masukkan Lokasi Tujuan: ";
                getline(cin, tujuan);
                cout << "Masukkan Jarak/Bobot: ";
                cin >> bobot;
            if(graph_kampus.find(asal) == graph_kampus.end() || graph_kampus.find(tujuan) == graph_kampus.end()){
                cout << "Error: Salah satu atau kedua lokasi belum terdaftar!" << endl << endl;
                continue;
            }
            graph_kampus[asal].push_back({tujuan, bobot});
            graph_kampus[tujuan].push_back({asal, bobot});
            cout << "Jalur antara \"" << asal << "\" dan \"" << tujuan << "\" dengan jarak " << bobot << " berhasil ditambahkan!" << endl << endl;
            riwayat_aktivitas.push_back("Menambahkan Edge Navigasi: " + asal + " - " + tujuan + " (" + to_string(bobot) + ")");
        }else if(opsi == 1){
            string asal, tujuan;
            cout << "Masukkan Lokasi Asal: ";
            cin.ignore();
            getline(cin, asal);
            cout << "Masukkan Lokasi Tujuan: ";
            getline(cin, tujuan);
            if(graph_kampus.find(asal) == graph_kampus.end() || graph_kampus.find(tujuan) == graph_kampus.end()){
                cout << "Lokasi asal atau tujuan tidak valid/tidak ditemukan!" << endl << endl;
                continue;
            }
            unordered_map<string,int> dist;
            unordered_map<string,string> parent;
            for(auto const& [key, val] : graph_kampus) dist[key] = 1e9;
            priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
            dist[asal] = 0;
            pq.push({0, asal});
            while(!pq.empty()){
                string u = pq.top().second;
                int d = pq.top().first;
                pq.pop();
                if(d > dist[u]) continue;
                for(auto const& edge : graph_kampus[u]){
                    string v = edge.first;
                    int weight = edge.second;
                    if(dist[u] + weight < dist[v]){
                        dist[v] = dist[u] + weight;
                        parent[v] = u;
                        pq.push({dist[v], v});
                    }
                }
            }
            if(dist[tujuan] == (int)1e9) cout << "Tidak ada rute dari " << asal << " ke " << tujuan << endl << endl;
            else{
                cout << "Rute terpendek ditemukan dengan total jarak: " << dist[tujuan] << endl;
                vector<string> path;
                string curr = tujuan;
                while(curr != asal){
                    path.push_back(curr);
                    curr = parent[curr];
                }
                path.push_back(asal);
                reverse(path.begin(), path.end());
                cout << "Jalur: ";
                for(size_t i = 0; i < path.size(); i++){
                    cout << path[i];
                    if(i < path.size() - 1) cout << " -> ";
                }
                cout << endl << endl;
                riwayat_aktivitas.push_back("Mencari rute dari " + asal + " ke " + tujuan + " (Jarak: " + to_string(dist[tujuan]) + ")");
            }
        }else{
            cout << "Opsi tidak ditemukan!" << endl;
        }
    }
}

// Operasi KRS
void operasi_krs(){
    cout << "===================================" << endl;
    cout << "\tLayanan KRS" << endl;
    cout << "===================================" << endl << endl;
    int opsi;
    while(true){
        cout << "1. Tambahkan KRS" << endl;
        cout << "2. Hapus pilihan terbaru" << endl;
        cout << "3. Lihat pilihan terbaru" << endl;
        cout << "4. Kembali" << endl << endl;
        cout << "Pilih Opsi: ";
        cin >> opsi;
        cout << endl;
        if(opsi == 4) return;
        else if(opsi == 3){
            if(!stack_krs.empty()) cout << "Pilihan terbaru: " << stack_krs.top() << endl;
            else cout << "KRS kosong!" << endl;
        }else if(opsi == 2){
            if(!stack_krs.empty()){
                cout << "Menghapus KRS: " << stack_krs.top() << endl;
                riwayat_aktivitas.push_back("Menghapus KRS: " + stack_krs.top());
                stack_krs.pop();
                cout << "Penghapusan berhasil!" << endl;
            }else cout << "KRS kosong!" << endl;
        }else if(opsi == 1){
            string pilihan;
            cout << "Masukkan nama mata kuliah: ";
            cin.ignore();
            getline(cin, pilihan);
            cout << endl;
            stack_krs.push(pilihan);
            riwayat_aktivitas.push_back("Menambahkan KRS: " + pilihan);
            cout << "Pilihan " << pilihan << " berhasil ditambahkan!" << endl;
        }else cout << "Opsi tidak ditemukan!" << endl;
    }
}

// Prioritas Layanan
void prioritas(){
    cout << "===================================" << endl;
    cout << "\tPrioritas Layanan" << endl;
    cout << "===================================" << endl << endl;
    int opsi;
    while(true){
        cout << "1. Tambahkan Layanan" << endl;
        cout << "2. Hapus pilihan terbaru" << endl;
        cout << "3. Lihat pilihan terbaru" << endl;
        cout << "4. Kembali" << endl << endl;
        cout << "Pilih Opsi: ";
        cin >> opsi;
        cout << endl;
        if(opsi == 4) return;
        else if(opsi == 3){
            if(!layanan_prioritas.empty()) cout << "Mahasiswa prioritas tertinggi: " << layanan_prioritas.top().nama << endl;
            else cout << "Antrian prioritas kosong!" << endl;
        }else if(opsi == 2){
            if(!layanan_prioritas.empty()){
                cout << "Mengambil Mahasiswa prioritas tertinggi: " << layanan_prioritas.top().nama << endl;
                riwayat_aktivitas.push_back("Melayani Layanan Prioritas: " + layanan_prioritas.top().nama);
                layanan_prioritas.pop();
                cout << "Penghapusan berhasil!" << endl;
            }else cout << "Antrian prioritas kosong!" << endl;
        }else if(opsi == 1){
            string nama, prio;
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama;
            cout << "Masukkan prioritas mahasiswa (Beasiswa/Disabilitas/Tingkat Akhir/Lainnya): ";
            cin.ignore();
            getline(cin, prio);
            int pr;
            if(prio == "Beasiswa") pr = 4;
            else if(prio == "Disabilitas") pr = 3;
            else if(prio == "Tingkat Akhir") pr = 2;
            else pr = 1;
            layanan_prioritas.push({pr, nama});
            riwayat_aktivitas.push_back("Menambahkan Layanan Prioritas: " + nama + " (" + prio + ")");
            cout << "Pilihan " << nama << " berhasil ditambahkan!" << endl;
        }else cout << "Opsi tidak ditemukan!" << endl;
    }
}

// Cari Akun
void cari_akun(){
    string query;
    cout << "===================================" << endl;
    cout << "Cari Akun (ketik exit untuk keluar)" << endl;
    cout << "===================================" << endl << endl;
    while(query != "exit"){
        cout << "Masukkan Username: ";
        cin >> query;
        cout << endl;
        if(query == "exit") break;
        auto findUsername = akun_mahasiswa.find(query);
        if(findUsername != akun_mahasiswa.end()){
            cout << "Username : " << query << endl;
            cout << "Nama     : " << akun_mahasiswa[query].nama << endl;
            cout << "NIM      : " << akun_mahasiswa[query].nim << endl;
            cout << "Prodi    : " << akun_mahasiswa[query].prodi << endl;
            cout << "Semester : " << akun_mahasiswa[query].semester << endl << endl;
        }else cout << "Username tidak ditemukan!" << endl << endl;
        riwayat_aktivitas.push_back("Mencari Akun");
    }
}

// Login
void login(){
    string username, pw;
    cout << "Masukkan Username : ";
    cin >> username;
    auto found = akun_mahasiswa.find(username);
    if(found == akun_mahasiswa.end()){
        cout << "Error: Mahasiswa tidak ditemukan!" << endl << endl;
        return;
    }
    cout << "Masukkan Password : ";
    cin >> pw;
    if(pw != akun_mahasiswa[username].password){
        cout << "Error: Password salah!" << endl << endl;
        return;
    }
    sudah_login = true;
    mahasiswa_aktif = akun_mahasiswa[username];
    cout << "Selamat Datang " << akun_mahasiswa[username].nama << "!" << endl << endl;
    riwayat_aktivitas.push_back("Login akun " + username);
}

// Buat Akun
void buat_akun(){
    Mahasiswa m;
    string username;

    cout << "Masukkan username : ";
    cin >> username;

    cout << "Nama              : ";
    cin.ignore();
    getline(cin, m.nama);

    cout << "NIM               : ";
    cin >> m.nim;

    cout << "Prodi             : ";
    cin.ignore();
    getline(cin, m.prodi);

    cout << "Password          : ";
    cin >> m.password;

    cout << "Semester          : ";
    cin >> m.semester;

    akun_mahasiswa[username] = m;
    cout << endl << "Akun sudah ditambahkan!" << endl;
    cout << "Silahkan Login!" << endl << endl;
    riwayat_aktivitas.push_back("Membuat akun " + username);
}

int main(){
    cout << endl << "==================================================" << endl;
    cout << "Selamat Datang di Smart Campus Navigation System!" << endl;
    cout << "==================================================" << endl << endl;
    mockdata();
    while(!sudah_login){
        cout << "1. Login" << endl;
        cout << "2. Buat Akun" << endl << endl;
        int log_or_reg;
        cout << "Pilih Opsi: ";
        cin >> log_or_reg;
        if(log_or_reg == 1) login();
        else if(log_or_reg == 2) buat_akun();
        else cout << "Opsi tidak ditemukan!" << endl;
    }
    while(true){
        cout << "==============================================" << endl;
        cout << "Daftar layanan Smart Campus Navigation System" << endl;
        cout << "==============================================" << endl;
        cout << "1. Riwayat Aktivitas" << endl;
        cout << "2. Antrian Konsultasi" << endl;
        cout << "3. Struktur Organisasi" << endl;
        cout << "4. Navigasi Kampus" << endl;
        cout << "5. Operasi KRS" << endl;
        cout << "6. Prioritas Layanan" << endl;
        cout << "7. Cari Akun" << endl << endl;
        int layanan;
        cout << "Pilih Layanan: ";
        cin >> layanan;
        cout << endl;
        switch(layanan){
        case 1:
            riwayat();
            break;
        case 2:
            antrian();
            break;
        case 3:
            struktur();
            break;
        case 4:
            navigasi();
            break;
        case 5:
            operasi_krs();
            break;
        case 6:
            prioritas();
            break;
        case 7:
            cari_akun();
            break;
        default:
            cout << "Layanan tidak ditemukan!" << endl;
        }
        cout << endl;
    }
    return 0;
}
