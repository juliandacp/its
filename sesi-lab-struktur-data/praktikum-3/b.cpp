#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;
    cin >> N;
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int matrix[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> matrix[i][j];
    }
    if(matrix[x1][y1] == 1 ||matrix[x2][y2] == 1){
        cout << "NO" << endl;
        return 0;
    }
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;
    while(!q.empty()){
        auto[x, y] = q.front();
        q.pop();
        if(x == x2 && y == y2){
            cout << "YES" << endl;
            return 0;
        }
        for(int i = 0; i < 8; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && !visited[next_x][next_y] && matrix[next_x][next_y] == 0){
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}