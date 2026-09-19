#include <bits/stdc++.h>
using namespace std;

class MyQueue{
public:
    stack<int> s1, s2;
    void push(int x){
        s1.push(x);
    }
    void move(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    int pop(){
        move();
        int val = s2.top();
        s2.pop();
        return val;
    }
    int peek(){
        move();
        return s2.top();
    }
    bool empty(){
        return s1.empty() && s2.empty();
    }
};

/*
int main(){
    MyQueue myQueue;
    int q;
    cin >> q;
    while(q--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            myQueue.push(x);
        }
        else if(cmd == "pop"){
            if(!myQueue.empty()) cout << myQueue.pop() << endl;
            else cout << "Queue kosong\n";
        }
        else if(cmd == "peek"){
            if(!myQueue.empty()) cout << myQueue.peek() << endl;
            else cout << "Queue kosong\n";
        }
        else if(cmd == "empty"){
            cout << myQueue.empty() << endl;
        }
    }
}
*/