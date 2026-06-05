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
    void display(){
        for(int i = 0; i < V; i++){
            cout << i << " -> ";
            for(int node : adj[i]) cout << node << " ";
            cout << endl;
        }
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.display();
    return 0;
}