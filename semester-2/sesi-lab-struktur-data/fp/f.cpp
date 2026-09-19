#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge{
    int u, v;
};

struct DSU{
    vector<int> parent;
    int group;
    DSU(int n){
        parent = vector<int>(n + 1); 
        group = n;        
        for(int i = 1; i <= n; i++) parent[i] = i;
    }    
    int find_set(int v){
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }   
    bool union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            parent[b] = a;
            group--;
            return true;
        }
        return false;
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M + 1);
    for(int i = 1; i <= M; i++) cin >> edges[i].u >> edges[i].v;
    int Q;
    cin >> Q;
    vector<int> collapse(Q);
    vector<bool> is_collapse(M + 1, false);
    for(int i = 0; i < Q; i++){
        cin >> collapse[i];
        is_collapse[collapse[i]] = true;
    }
    DSU dsu(N);
    for(int i = 1; i <= M; i++){
        if(!is_collapse[i]) dsu.union_sets(edges[i].u, edges[i].v);
    }
    vector<int> ans(Q);
    for(int i = Q - 1; i >= 0; i--){
        ans[i] = dsu.group;
        int edge_idx = collapse[i];
        dsu.union_sets(edges[edge_idx].u, edges[edge_idx].v);
    }
    for(int i = 0; i < Q; i++) cout << ans[i] << endl;
    return 0;
}