#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int Q;
    cin >> Q;
    deque<string> dq;
    while(Q--){
        string cmd;
        cin >> cmd;
        if(cmd == "PUSH_FRONT"){
            string X;
            cin >> X;
            dq.push_front(X);
        }else if(cmd== "PUSH_BACK"){
            string X;
            cin >> X;
            dq.push_back(X);
        }else if(cmd == "POP_FRONT"){
            if(!dq.empty()) dq.pop_front();
        }else if(cmd == "POP_BACK"){
            if(!dq.empty()) dq.pop_back();
        }
    }
    if(dq.empty()) cout << "KOSONG" << endl;
    else{
        for(int i = 0; i < dq.size(); i++){
            if(i > 0) cout << ' ';
            cout << dq[i];
        }
        cout << endl;
    }
    return 0;
}