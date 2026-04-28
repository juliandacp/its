#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Cek prioritas operator
int priority(char op){
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Cek operator
bool is_operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infix_to_postfix(string infix) {
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        // Operand (huruf/angka)
        if(isalnum(c)){
            postfix += c;
            postfix += " ";
        }
        // Buka kurung
        else if(c == '('){
            st.push(c);
        }
        // Tutup kurung
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.pop();
        }
        // Operator
        else if(is_operator(c)) {
            while(!st.empty() && priority(st.top()) >= priority(c)){
                postfix += st.top();
                postfix += " ";
                st.pop();
            }
            st.push(c);
        }
    }
    // Pop sisa stack
    while(!st.empty()){
        postfix += st.top();
        postfix += " ";
        st.pop();
    }
    return postfix;
}

int main(){
    string infix = "a+(2*b^3)/(f-g)+d*h";
    cout << "Infix   : " << infix << endl;
    cout << "Postfix : " << infix_to_postfix(infix) << endl;
    return 0;
}