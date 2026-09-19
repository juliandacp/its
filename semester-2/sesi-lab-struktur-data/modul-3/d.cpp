#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1005];
bool visited[1005];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto next : adj[node]){
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int Q;
        cin >> Q;
        for(int j = 0; j < Q; j++){
            int K;
            cin >> K;
            adj[i].push_back(K);
        }
    }
    bfs(0);
    bool area = true;
    for(int i = 0; i < N; i++){
        if(!visited[i]) area = false;
    }
    if(area) cout << "Para peserta LBH berhasil keluar!" << endl;
    else cout << "Para peserta LBH terjebak selamanya." << endl;
    return 0;
}