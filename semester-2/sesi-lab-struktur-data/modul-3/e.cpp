#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[105];
bool visited[105];

void dfs(int node){
    visited[node] = true;
    for(auto next : adj[node]){
        if(!visited[next]) dfs(next);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) cin >> num[i];
    int c;
    cin >> c;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int res = num[i] ^ num[j];
            if(res % c == 0){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int kelompok = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            kelompok++;
        }
    }
    cout << kelompok << endl;
    return 0;
}