#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct edge{
    int target;
    int weight;
};

class social_network{
private:
    int total_vertex;
    vector<vector<edge>> adjList;
    vector<string> user_name;

public:
    social_network(int vertex){
        total_vertex = vertex;
        adjList.resize(vertex);
        user_name.resize(vertex);
    }

    void set_user_name(int id, string name){
        if(id >= 0 && id < total_vertex) user_name[id] = name;
    }

    void add_edge(int source, int target, int weight){
        adjList[source].push_back({target, weight});
        adjList[target].push_back({source, weight});
    }

    void print_graph(){
        cout << endl;
        cout << "=========================================" << endl;
        cout << "           GRAPH REPRESENTATION          " << endl;
        cout << "=========================================" << endl;
        for(int i = 0; i < total_vertex; ++i){
            cout << user_name[i] << " (" << i << ") -> ";
            for(const auto& e : adjList[i]) cout << "[" << user_name[e.target] << " (weight: " << e.weight << ")] ";
            cout << endl;
        }
    }

    void bfs(int start){
        vector<bool> visited(total_vertex, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << endl << "[BFS] Friendship Level Traversal from " << user_name[start] << ":" << endl;
        while(!q.empty()){
            int order = q.front();
            cout << user_name[order] << " -> ";
            q.pop();
            for(const auto& e : adjList[order]){
                if(!visited[e.target]){
                    visited[e.target] = true;
                    q.push(e.target);
                }
            }
        }
        cout << "DONE" << endl;
    }

    void dfs(int start){
        vector<bool> visited(total_vertex, false);
        stack<int> s;
        s.push(start);
        cout << endl << "[DFS] Deep Path Traversal from " << user_name[start] << ":" << endl;
        while(!s.empty()){
            int order = s.top();
            s.pop();
            if(!visited[order]){
                cout << user_name[order] << " -> ";
                visited[order] = true;
            }
            for(auto it = adjList[order].rbegin(); it != adjList[order].rend(); ++it){
                if(!visited[it->target]){
                    s.push(it->target);
                }
            }
        }
        cout << "DONE" << endl;
    }

    void dijkstra(int start){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(total_vertex, INT_MAX);
        vector<int> parent(total_vertex, -1);
        distance[start] = 0;
        pq.push({0, start});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(const auto& e : adjList[u]){
                int v = e.target;
                int edge_weight = e.weight;
                if(distance[u] != INT_MAX && distance[u] + edge_weight < distance[v]){
                    distance[v] = distance[u] + edge_weight;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }
        cout << endl << "[DIJKSTRA] Shortest Path Relationship from " << user_name[start] << ":" << endl;
        for(int i = 0; i < total_vertex; ++i){
            if(i == start) continue;
            cout << "To " << user_name[i] << " (Total Weight: " << distance[i] << ") | Path: ";
            int curr = i;
            vector<string> path;
            while(curr != -1){
                path.push_back(user_name[curr]);
                curr = parent[curr];
            }
            for(auto it = path.rbegin(); it != path.rend(); ++it){
                cout << *it << (it + 1 != path.rend() ? " -> " : "");
            }
            cout << endl;
        }
    }
};

int main() {
    // 1. Inisialisasi Graf dengan 8 Vertex
    social_network sosmed(8);

    // 3 & 5. Menghubungkan Relasi Pertemanan dengan Bobot Kedekatan
    sosmed.set_user_name(0, "Andi");
    sosmed.set_user_name(1, "Budi");
    sosmed.set_user_name(2, "Cindi");
    sosmed.set_user_name(3, "Dodi");
    sosmed.set_user_name(4, "Edi");
    sosmed.set_user_name(5, "Faldi");
    sosmed.set_user_name(6, "Gordi");
    sosmed.set_user_name(7, "Hendi");

    sosmed.add_edge(0, 1, 2);
    sosmed.add_edge(0, 2, 5);
    sosmed.add_edge(1, 3, 4);
    sosmed.add_edge(2, 4, 1);
    sosmed.add_edge(3, 5, 7);
    sosmed.add_edge(4, 5, 3);
    sosmed.add_edge(4, 6, 8);
    sosmed.add_edge(5, 7, 2);
    sosmed.add_edge(6, 7, 1);

    sosmed.print_graph();

    // 2. Eksekusi Pencarian BFS dan DFS
    sosmed.bfs(0);
    sosmed.dfs(0);

    // 4. Analisis Jalur Terpendek menggunakan Dijkstra
    sosmed.dijkstra(0);

    cout << endl;
    return 0;
}