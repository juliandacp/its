#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2, 4, 6, 8};
    for(int i = 0; i < 4; i++){
        cout << arr[i] << endl;
        cout << "Id: " << &arr[i] << endl;
    }
    return 0;
}