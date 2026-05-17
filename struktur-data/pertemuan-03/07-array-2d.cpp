#include <bits/stdc++.h>
using namespace std;

int main(){
    int matrix[3][4] = {{255, 255, 250, 240},
                        {150, 200, 255, 225},
                        {  0,  50, 150, 200}};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}