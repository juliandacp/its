#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph{
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices){
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int start){
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            cout << v << " ";
            for(int u : adj[v]){
                if(!visited[u]){
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    cout << "BFS : ";
    g.BFS(0);
    return 0;
}