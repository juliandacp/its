#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Stack{
private:
    int *arr;
    int top;
    int kapasitas;

public:
    Stack(int size){
        kapasitas = size;
        arr = new int[kapasitas];
        top = -1;
    }
    void push(int x){
        if(top == kapasitas - 1){
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    void pop(){
        if(top == -1){
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Elemen yang dihapus: " << arr[top--] << endl;
    }
    void peek(){
        if(top == -1) cout << "Stack kosong\n";
        else cout << "Elemen teratas: " << arr[top] << endl;
    }
    void display(){
        if(top == -1){
            cout << "Stack kosong\n";
            return;
        }
        for(int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
    ~Stack(){
        delete[] arr;
    }
};

int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    return 0;
}