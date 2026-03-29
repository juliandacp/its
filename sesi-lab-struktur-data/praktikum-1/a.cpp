#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    int cek = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            st.push(s[i]);
            continue;
        }
        if(st.empty()){
            cek = 0;
            break;
        }
        char x = st.top();
        if(s[i] == '}' && x == '{') st.pop();
        else if(s[i] == ')' && x == '(') st.pop();
        else if(s[i] == ']' && x == '[') st.pop();
        else{
            cek = 0;
            break;
        }
    }
    if(!st.empty() || !cek) cout << "FAIL" << endl;
    else cout << "COMBO" << endl;
    return 0;
}