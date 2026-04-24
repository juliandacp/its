#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    map<string, pair<int, string>> data;
    int N;
    cin >> N;
    while(N--){
        string label;
        string nama, asal;
        int usia;
        cin >> label >> nama;   
        cin >> label >> usia;
        cin >> label >> asal;   
        data[nama] = make_pair(usia, asal);
    }
    int Q;
    cin >> Q;
    while(Q--){
        string nama;
        cin >> nama;
        cout << "Usia: " << data[nama].first << endl;
        cout << "Asal: " << data[nama].second << endl;
    }
    return 0;
}