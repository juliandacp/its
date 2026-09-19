#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<pair<int, int>, bool> visited;

void bfs(pair<int, int> start, vector<string> matrix, int ukuran){
    queue<pair<int, int>> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int n = q.front().first;
        int m = q.front().second;
        q.pop();
        if(n + 1 < ukuran && m + 1 < ukuran && matrix[n + 1][m + 1] == '+' && !visited[{n + 1, m + 1}]){
            q.push({n + 1, m + 1});
            visited[{n + 1, m + 1}] = true;
        }
        if(n - 1 >= 0 && m - 1 >= 0 && matrix[n - 1][m - 1] == '+' && !visited[{n - 1, m - 1}]){
            q.push({n - 1, m - 1});
            visited[{n - 1, m - 1}] = true;
        }
        if(n - 1 >= 0 && m + 1 < ukuran && matrix[n - 1][m + 1] == '+' && !visited[{n - 1, m + 1}]){
            q.push({n - 1, m + 1});
            visited[{n - 1, m + 1}] = true;
        }
        if(n + 1 < ukuran && m - 1 >= 0 && matrix[n + 1][m - 1] == '+' && !visited[{n + 1, m - 1}]){
            q.push({n + 1, m - 1});
            visited[{n + 1, m - 1}] = true;
        }
        if(n + 1 < ukuran && matrix[n + 1][m] == '+' && !visited[{n + 1, m}]){
            q.push({n + 1, m});
            visited[{n + 1, m}] = true;
        }
        if(n - 1 >= 0 && matrix[n - 1][m] == '+' && !visited[{n - 1, m}]){
            q.push({n - 1, m});
            visited[{n - 1, m}] = true;
        }
        if(m + 1 < ukuran && matrix[n][m + 1] == '+' && !visited[{n, m + 1}]){
            q.push({n, m + 1});
            visited[{n, m + 1}] = true;
        }
        if(m - 1 >= 0 && matrix[n][m - 1] == '+' && !visited[{n, m - 1}]){
            q.push({n, m - 1});
            visited[{n, m - 1}] = true;
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<string> matrix;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        matrix.push_back(s);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[{i, j}] = false;
        }
    }
    int kelompok = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matrix[i][j] == '+' && !visited[{i, j}]){
                kelompok++;
                bfs({i, j}, matrix, N);
            }
        }
    }
    cout << kelompok << endl;
    return 0;
}