#include <bits/stdc++.h>
#define ll long long
using namespace std;

int index(vector<string>& names, string target){
    for(int i = 0; i < names.size(); i++){
        if(names[i] == target) return i;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<string> names(n);
    for(int i = 0; i < n; i++) cin >> names[i];
    vector<int> to(n);
    for(int i = 0; i < n; i++){
        string x, y;
        cin >> x >> y;
        int u = index(names, x);
        int v = index(names, y);
        to[u] = v;
    }
    string a, b;
    cin >> a >> b;
    int start = index(names, a);
    int end = index(names, b);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cek = q.front();
        q.pop();
        if(visited[cek]) continue;
        visited[cek] = true;
        if(cek == end){
            cout << "Oalah, ez ini mah!" << endl;
            return 0;
        }
        q.push(to[cek]);
    }
    cout << "cooked" << endl;
    return 0;
}