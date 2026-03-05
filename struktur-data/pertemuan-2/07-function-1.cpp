#include <bits/stdc++.h>
using namespace std;

void vowel_or_consonant(char x){
    if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o'
        || x == 'A' || x == 'I' || x == 'U' || x == 'E' || x == 'O')
        cout << x << " is Vowel" << endl;
    else cout << x << " is Consonant" << endl;
}

int main(){
    char letter1, letter2;
    cin >> letter1 >> letter2;
    vowel_or_consonant(letter1);
    vowel_or_consonant(letter2);
    return 0;
}