#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bfs(int start, vector<int>& dist, vector<int> adj[], int n){
    fill(dist.begin(), dist.end(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        vector<int> adj[n+1];
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> dist(n+1, vector<int>(n+1));
        for(int i = 1; i <= n; i++) bfs(i, dist[i], adj, n);
        int ans = 0;
        for(int a = 1; a <= n; a++){
            for(int b = a+1; b <= n; b++){
                int d_ab = dist[a][b];
                for(int c = b+1; c <= n; c++){
                    int subtree_size = (d_ab + dist[b][c] + dist[c][a]) / 2 + 1;
                    if(subtree_size == d) ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}