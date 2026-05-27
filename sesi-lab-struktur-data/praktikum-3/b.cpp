#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, x, y;

int bfs(vector<vector<int>> &matrix){
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({x, y});
    visited[x][y] = true;

}

int main(){
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int matrix[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cout << bfs(matrix);
}
