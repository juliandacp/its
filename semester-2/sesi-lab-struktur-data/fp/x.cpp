#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dfs_size(int v, int p, vector<vector<int>>& adj, vector<int>& parent, vector<int>& depth, vector<int>& heavy){
    parent[v] = p;
    heavy[v] = -1;
    int subtree_size = 1;
    int max_child_size = 0;
    for(int u : adj[v]){
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        int child_size = dfs_size(u, v, adj, parent, depth, heavy);
        subtree_size += child_size;
        if(child_size > max_child_size){
            max_child_size = child_size;
            heavy[v] = u;
        }
    }
    return subtree_size;
}

void dfs_hld(int v, int h, vector<vector<int>>& adj, vector<int>& parent, vector<int>& heavy, vector<int>& head, vector<int>& pos, vector<int>& rev_pos, int& curr_pos){
    head[v] = h;
    pos[v] = ++curr_pos;
    rev_pos[curr_pos] = v;
    if(heavy[v] != -1) dfs_hld(heavy[v], h, adj, parent, heavy, head, pos, rev_pos, curr_pos);
    for(int u : adj[v]){
        if (u == parent[v] || u == heavy[v]) continue;
        dfs_hld(u, u, adj, parent, heavy, head, pos, rev_pos, curr_pos);
    }
}

void update(int node, int left, int right, int idx, int value, vector<int>& seg_tree){
    if(left == right){
        seg_tree[node] = value;
        return;
    }
    int mid = (left + right) / 2;
    if(idx <= mid) update(node * 2, left, mid, idx, value, seg_tree);
    else update(node * 2 + 1, mid + 1, right, idx, value, seg_tree);
    seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
}

int query(int node, int left, int right, int q_left, int q_right, vector<int>& seg_tree, vector<int>& rev_pos){
    if(q_left > q_right || seg_tree[node] == 0) return -1;
    if(left == right) return rev_pos[left];
    int mid = (left + right) / 2;
    int left_ans = query(node * 2, left, mid, q_left, min(q_right, mid), seg_tree, rev_pos);
    if(left_ans != -1) return left_ans;
    return query(node * 2 + 1, mid + 1, right, max(q_left, mid + 1), q_right, seg_tree, rev_pos);
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> adj(N + 1);
    for(int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> parent(N + 1);
    vector<int> depth(N + 1);
    vector<int> heavy(N + 1);
    vector<int> head(N + 1);
    vector<int> pos(N + 1);
    vector<int> rev_pos(N + 1);
    vector<int> state(N + 1, 0);
    vector<int> seg_tree(4 * N + 5, 0);
    int curr_pos = 0;
    dfs_size(1, 0, adj, parent, depth, heavy);
    dfs_hld(1, 1, adj, parent, heavy, head, pos, rev_pos, curr_pos);
    while(Q--){
        int type, x;
        cin >> type >> x;
        if(type == 0){
            state[x] ^= 1;
            update(1, 1, N, pos[x], state[x], seg_tree);
        }else{
            vector<pair<int, int>> paths;
            int curr = x;
            while(curr != 0){
                paths.push_back({pos[head[curr]], pos[curr]});
                curr = parent[head[curr]];
            }
            reverse(paths.begin(), paths.end());
            int ans = -1;
            for(auto p : paths){
                ans = query(1, 1, N, p.first, p.second, seg_tree, rev_pos);
                if(ans != -1) break;
            }
            cout << ans << endl;
        }
    }
    return 0;
}