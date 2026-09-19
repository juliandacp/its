#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct schedule{
    int mission;
    int value;
    int T;
    int L;
    int R;
};

void add_edge(int u, int v, vector<vector<int>>& graph, vector<vector<int>>& reverse_graph){
    graph[u].push_back(v);
    reverse_graph[v].push_back(u);
}

int literal_node(int mission, int value){
    return 2 * mission + value;
}

void dfs1(int u, vector<vector<int>>& graph, vector<int>& visited, vector<int>& order){
    visited[u] = 1;
    for(int v : graph[u]){
        if(!visited[v]) dfs1(v, graph, visited, order);
    }
    order.push_back(u);
}

void dfs2(int u, int id, vector<vector<int>>& reverse_graph, vector<int>& component){
    component[u] = id;
    for(int v : reverse_graph[u]){
        if(component[v] == -1) dfs2(v, id, reverse_graph, component);
    }
}

int main(){
    int N;
    cin >> N;
    vector<schedule> schedules;
    schedules.reserve(2 * N);
    for(int i = 0; i < N; i++){
        int TA, LA, RA;
        int TB, LB, RB;
        cin >> TA >> LA >> RA >> TB >> LB >> RB;
        schedules.push_back({i, 0, TA, LA, RA});
        schedules.push_back({i, 1, TB, LB, RB});
    }
    int nodes = 2 * N;
    vector<vector<int>> graph(nodes);
    vector<vector<int>> reverse_graph(nodes);
    int M = schedules.size();
    for(int i = 0; i < M; i++){
        for(int j = i + 1; j < M; j++){
            if(schedules[i].mission == schedules[j].mission) continue;
            if (schedules[i].T != schedules[j].T) continue;
            int overlap_L = max(schedules[i].L, schedules[j].L);
            int overlap_R = min(schedules[i].R, schedules[j].R);
            if(overlap_L < overlap_R){
                int a = literal_node(schedules[i].mission, schedules[i].value);
                int b = literal_node(schedules[j].mission, schedules[j].value);
                add_edge(a, b ^ 1, graph, reverse_graph);
                add_edge(b, a ^ 1, graph, reverse_graph);
            }
        }
    }
    vector<int> visited(nodes, 0);
    vector<int> order;
    for(int i = 0; i < nodes; i++){
        if(!visited[i]) dfs1(i, graph, visited, order);
    }
    reverse(order.begin(), order.end());
    vector<int> component(nodes, -1);
    int connect_count = 0;
    for(int u : order){
        if(component[u] == -1){
            dfs2(u, connect_count, reverse_graph, component);
            connect_count++;
        }
    }
    for(int i = 0; i < N; i++){
        if(component[2 * i] == component[2 * i + 1]){
            cout << "RIFT COLLAPSED" << endl;
            return 0;
        }
    }
    cout << "RIFT SEALED" << endl;
    return 0;
}