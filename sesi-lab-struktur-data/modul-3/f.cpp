#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;

int bfs(vector<string> &matrix, int a, int b){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    q.push({a, b});
    visited[a][b] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(matrix[x][y] == '1') return dis[x][y];
        if(x + 1 < n && !visited[x + 1][y]){
            q.push({x + 1, y});
            visited[x + 1][y] = true;
            dis[x + 1][y] = dis[x][y] + 1;
        }
        if(x - 1 >= 0 && !visited[x - 1][y]){
            q.push({x - 1, y});
            visited[x - 1][y] = true;
            dis[x - 1][y] = dis[x][y] + 1;
        }
        if(y + 1 < m && !visited[x][y + 1]){
            q.push({x, y + 1});
            visited[x][y + 1] = true;
            dis[x][y + 1] = dis[x][y] + 1;
        }
        if(y - 1 >= 0 && !visited[x][y - 1]){
            q.push({x, y - 1});
            visited[x][y - 1] = true;
            dis[x][y - 1] = dis[x][y] + 1;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> matrix;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            matrix.push_back(s);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    cout << 0 << " ";
                    continue;
                }
                cout << bfs(matrix, i, j) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}