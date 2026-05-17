#include <bits/stdc++.h>
using namespace std;

int main(){
    int rows, columns, n, num = 1;
    cin >> n;
    for(int rows = 0; rows <= n; rows++){
        for(int columns = 0; columns < rows; columns++) cout << num++ << " ";
        cout << endl;
    }
    return 0;
}