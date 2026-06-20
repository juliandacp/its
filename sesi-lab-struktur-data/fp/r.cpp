#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int Q;
    cin >> Q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(Q--){
        string cmd;
        cin >> cmd;
        if(cmd == "ADD"){
            int x;
            cin >> x;
            pq.push(x);
        }else if(cmd == "BUY"){
            if(pq.empty()) cout << -1 << endl;
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
    return 0;
}