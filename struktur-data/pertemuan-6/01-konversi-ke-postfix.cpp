#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Fungsi untuk menentukan prioritas operator
int precedence(char op){
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}

// Fungsi untuk cek apakah karakter adalah operator
bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Fungsi utama konversi infix ke postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if(isalnum(c)) postfix += c; // Jika operand (huruf/angka)
        else if(c == '(') st.push(c); // Jika '('
        // Jika ')'
        else if(c == ')'){
            while (!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // hapus '('
        }
        // Jika operator
        else if(isOperator(c)){
            while (!st.empty() && precedence(st.top()) >= precedence(c)){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    // Pop semua operator tersisa
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// Main function
int main(){
    string infix;
    cout << "Masukkan ekspresi infix: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}