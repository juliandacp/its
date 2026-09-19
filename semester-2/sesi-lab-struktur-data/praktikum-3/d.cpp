#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N, M, KS, KC, KR;
    cin >> N >> M >> KS >> KC >> KR;
    char P[N + 1];
    for(int i = 1; i <= N; i++) cin >> P[i];
    vector<int> adj[N + 1];
    for(int i = 1; i <= M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> team(N + 1, -1);
    queue<int> q;
    team[1] = 1;
    q.push(1);
    while(!q.empty()){
        int member = q.front();
        q.pop();
        for(int neighbor : adj[member]){
            if(team[neighbor] == -1){
                team[neighbor] = 3 - team[member];
                q.push(neighbor);
            }
            else if(team[member] == team[neighbor]){
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    int s1 = 0, c1 = 0, r1 = 0;
    int s2 = 0, c2 = 0, r2 = 0;
    for(int i = 1; i <= N; i++){
        if(team[i] == 1){
            if(P[i] == 'S') s1++;
            else if(P[i] == 'C') c1++;
            else r1++;
        }else{
            if(P[i] == 'S') s2++;
            else if(P[i] == 'C') c2++;
            else r2++;
        }
    }
    if(s1 >= KS && s2 >= KS && c1 >= KC && c2 >= KC && r1 >= KR && r2 >= KR){
        for(int i = 1; i <= N; i++) cout << team[i] << " ";
        cout << endl;
    }else cout << "IMPOSSIBLE" << endl;
    return 0;
}