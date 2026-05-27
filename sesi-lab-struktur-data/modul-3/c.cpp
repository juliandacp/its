#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, x, y;

int bfs(vector<vector<int>> &matrix){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({x, y});
    visited[x][y] = true;
    int luas = 0;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        luas++;
        if(a + 1 < n && !visited[a + 1][b] && matrix[a + 1][b] <= matrix[a][b]){
            q.push({a + 1, b});
            visited[a + 1][b] = true;
        }
        if(a - 1 >= 0 && !visited[a - 1][b] && matrix[a - 1][b] <= matrix[a][b]){
            q.push({a - 1, b});
            visited[a - 1][b] = true;
        }
        if(b + 1 < m && !visited[a][b + 1] && matrix[a][b + 1] <= matrix[a][b]){
            q.push({a, b + 1});
            visited[a][b + 1] = true;
        }
        if(b - 1 >= 0 && !visited[a][b - 1] && matrix[a][b - 1] <= matrix[a][b]){
            q.push({a, b - 1});
            visited[a][b - 1] = true;
        }
    }
    return luas;
}

int main(){
    cin >> n >> m >> x >> y;
    x--;
    y--;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> matrix[i][j];
    }
    cout << bfs(matrix) << endl;
    return 0;
}