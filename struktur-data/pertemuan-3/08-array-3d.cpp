#include <bits/stdc++.h>
using namespace std;

int main(){
    int nilai[2][3][4] = {{{85, 90, 78, 92},
                           {76, 88, 95, 82},
                           {92, 85, 80, 88}},
                          {{78, 85, 90, 87},
                           {95, 82, 79, 91},
                           {70, 88, 85, 90}}};
    for(int layer = 0; layer < 2; layer++){
        for(int baris = 0; baris < 3; baris++){
            for(int kolom = 0; kolom < 4; kolom++) cout << nilai[layer][baris][kolom] << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}