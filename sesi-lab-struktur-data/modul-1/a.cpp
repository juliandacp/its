#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    deque<char> s;
    string perintah;
    while(cin >> perintah && perintah != "PRINT"){
        if(perintah == "WRITE"){
            char x;
            cin >> x;
            s.push_front(x);
        }else if(perintah == "BACKSPACE"){
            s.pop_front();
        }
    }
    while(!s.empty()){
        cout << s.back();
        s.pop_back();
    }
    cout << endl;
    return 0;
}