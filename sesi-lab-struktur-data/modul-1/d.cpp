#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;
    cin >> N;
    priority_queue<ll> data;
    while(N--){
        ll X;
        cin >> X;
        data.push(X);
    }
    while(data.size() > 1){
        ll max1 = data.top();
        data.pop();
        ll max2 = data.top();
        data.pop();
        if(max1 == max2) continue;
        else data.push(max1 - max2);
    }
    if(data.empty()) cout << 0 << endl;
    else cout << data.top() << endl;
    return 0;
}