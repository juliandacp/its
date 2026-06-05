#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        if(pos > 1 && dist[pos - 1] == -1){
            dist[pos - 1] = dist[pos] + 1;
            q.push(pos - 1);
        }
        if(pos < n && dist[pos + 1] == -1){
            dist[pos + 1] = dist[pos] + 1;
            q.push(pos + 1);
        }
        int pow_jump = pos + a[pos];
        if(pow_jump <= n && dist[pow_jump] == -1){
            dist[pow_jump] = dist[pos] + 1;
            q.push(pow_jump);
        }
        if(dist[n] != -1) break;
    }
    cout << dist[n] << endl;
    return 0;
}
