#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, m, prov = 0;
    int arah_r[] = {-1, 0, 1, 0};
    int arah_c[] = {0, -1, 0, 1};
    cin >> n >> m;
    char matrix[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == '*') continue;
            else{
                if(!visited[i][j]){
                    prov++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while(!q.empty()){
                        auto[r, c] = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++){
                            int idx_r = r + arah_r[i];
                            int idx_c = c + arah_c[i];
                            if(idx_r >= 0 && idx_r < n && idx_c >= 0 && idx_c < m && !visited[idx_r][idx_c] && matrix[idx_r][idx_c] == 'K'){
                                q.push({idx_r, idx_c});
                                visited[idx_r][idx_c] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << prov << endl;
    return 0;
}
