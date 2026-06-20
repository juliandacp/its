#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    unordered_map<int, int> m;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int id;
            cin >> id;
            m[id] = i;
        }
    }
    vector<queue<int>> member(t);
    queue<int> q;
    string cmd;
    while(cin >> cmd){
        if(cmd == "ENQUEUE"){
            int x;
            cin >> x;
            int dept = m[x];
            if(member[dept].empty()) q.push(dept);
            member[dept].push(x);
        }else if(cmd == "DEQUEUE"){
            int dept = q.front();
            int student = member[dept].front();
            member[dept].pop();
            cout << student << endl;
            if(member[dept].empty()) q.pop();
        }
    }
    return 0;
}