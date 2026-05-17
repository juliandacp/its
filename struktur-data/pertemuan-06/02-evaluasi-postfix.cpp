#include <bits/stdc++.h>
using namespace std;

// Fungsi evaluasi postfix
int evaluatePostfix(string exp){
    stack<int> st;
    for(char c : exp){
        // Jika operand (angka)
        if(isdigit(c)) st.push(c - '0'); // Konversi char ke int
        // Jika operator
        else{
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch(c){
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

// Main
int main(){
    string postfix;
    cout << "Masukkan ekspresi postfix: ";
    cin >> postfix;
    cout << "Hasil evaluasi: " << evaluatePostfix(postfix) << endl;
    return 0;
}