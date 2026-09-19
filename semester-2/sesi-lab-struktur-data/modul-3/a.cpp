#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[100005];
bool visited[100005];

void dfs(int node){
    visited[node] = true;
    for(auto next : adj[node]){
        if(!visited[next]) dfs(next);
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int res = 0;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i);
            res++;
        }
    }
    if(res == 1) cout << "Kompleksitas entitas terbentuk";
    else cout << "Seluruh kosmik tidak berkaitan, butuh " << res - 1 << " lagi";
    cout << endl;
    return 0;
}