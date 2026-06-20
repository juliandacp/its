#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge{
    long long weight;
    int u, v;
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};

struct Query{
    ll P;
    int id;
    bool operator<(const Query& other) const{
        return P < other.P;
    }
};

struct DSU{
    vector<int> parent;
    int group;
    DSU(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        group = n;
    }    
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }   
    bool union_sets(int a, int b) {
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
    int N, Q;
    cin >> N >> Q;    
    vector<pair<int, int>> coordinates(N);
    for(int i = 0; i < N; ++i) cin >> coordinates[i].first >> coordinates[i].second;    
    vector<Edge> edges;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            long long dx = coordinates[i].first - coordinates[j].first;
            long long dy = coordinates[i].second - coordinates[j].second;
            long long dist = dx * dx + dy * dy;
            edges.push_back({dist, i, j});
        }
    }    
    sort(edges.begin(), edges.end());
    vector<Query> q(Q);
    for(int i = 0; i < Q; ++i){
        cin >> q[i].P;
        q[i].id = i;
    }
    sort(q.begin(), q.end());
    vector<int> ans(Q);
    DSU dsu(N);
    int edge_idx = 0;
    int num_edges = edges.size();
    for(int i = 0; i < Q; i++){
        while(edge_idx < num_edges && edges[edge_idx].weight <= q[i].P){
            dsu.union_sets(edges[edge_idx].u, edges[edge_idx].v);
            edge_idx++;
        }
        ans[q[i].id] = dsu.group;
    }    
    for(int i = 0; i < Q; i++) cout << ans[i] << endl;
    return 0;
}