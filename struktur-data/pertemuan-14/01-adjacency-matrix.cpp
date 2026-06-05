#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Graph{
private:
    int matrix[100][100];
    int vertices;

public:
    Graph(int v){
        vertices = v;
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++) matrix[i][j] = 0;
        }
    }
    void addEdge(int u, int v){
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    void display(){
        cout << "Adjacency Matrix" << endl;
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++) cout << matrix[i][j] << " ";
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