#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;
    cin >> N;
    stack<string> st;
    while(N--){
        string cmd;
        cin >> cmd;
        if(cmd == "PUSH"){
            string x;
            cin >> x;
            st.push(x);
        }else if(cmd == "POP"){
            if(!st.empty()) st.pop();
        }else if(cmd == "TOP"){
            if(st.empty()) cout << "KOSONG" << endl;
            else cout << st.top() << endl;
        }
    }
    return 0;
}