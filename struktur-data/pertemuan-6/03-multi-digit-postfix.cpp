#include <bits/stdc++.h>
#define ll long long
using namespace std;

int evaluatePostfix(string exp){
    stack<int> st;
    stringstream ss(exp);
    string token;
    while(ss >> token){
        // Jika operator
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            if(token == "+") st.push(val1 + val2);
            else if(token == "-") st.push(val1 - val2);
            else if(token == "*") st.push(val1 * val2);
            else if(token == "/") st.push(val1 / val2);
        }
        // Jika operand
        else st.push(stoi(token));
    }
    return st.top();
}

int main(){
    string postfix;
    cout << "Masukkan postfix (pisahkan dengan spasi): ";
    getline(cin, postfix);
    cout << "Hasil: " << evaluatePostfix(postfix) << endl;
    return 0;
}