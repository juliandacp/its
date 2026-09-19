#include <bits/stdc++.h>
#define ll long long
using namespace std;

void build_depth(vector<vector<int> > &child, vector<int> &depth, int n){
    vector<int> stack;
    stack.push_back(1);
    while(!stack.empty()){
        int node = stack.back();
        stack.pop_back();
        for(int i = 0; i < child[node].size(); i++){
            int next = child[node][i];
            depth[next] = depth[node] + 1;
            stack.push_back(next);
        }
    }
}

int find_admin(int a, int b, vector<int> &depth, vector<vector<int> > &up, int LOG){
    if(depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i = LOG - 1; i >= 0; i--){
        if(diff & (1 << i)) a = up[a][i];
    }
    if(a == b) return a;
    for(int i = LOG - 1; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    int n, q;
    cin >> n >> q;
    int LOG = 1;
    while((1 << LOG) <= n) LOG++;
    vector<vector<int> > child(n + 1);
    vector<vector<int> > up(n + 1, vector<int>(LOG, 0));
    vector<int> depth(n + 1, 0);
    for(int i = 2; i <= n; i++){
        int parent;
        cin >> parent;
        child[parent].push_back(i);
        up[i][0] = parent;
    }
    build_depth(child, depth, n);
    for(int j = 1; j < LOG; j++){
        for(int i = 1; i <= n; i++) up[i][j] = up[up[i][j - 1]][j - 1];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << find_admin(a, b, depth, up, LOG) << endl;
    }
    return 0;
}