#include<stdio.h>
#include<string.h>

int n;
char papan[105][105];

/*Misal: 0 = kiri
         1 = atas  
         2 = kanan
         3 = bawah
*/

void laser(int i, int j, int arah) {
    if(i<0 || i>=n || j<0 || j>=n) return;
    if(papan[i][j]=='/') {
        if(arah==0){
            laser(i+1, j, 3); 
        }
        else if(arah==1){ 
            laser(i, j+1, 2);
        }
        else if(arah==2){
            laser(i-1, j, 1); 
        }
        else if(arah==3){
            laser(i, j-1, 0);
        }
    }
    else if(papan[i][j]=='\\') {
        if(arah==0){
            laser(i-1, j, 1);
        }
        else if(arah==1){
            laser(i, j-1, 0);
        }
        else if(arah==2){
            laser(i+1, j, 3);
        }
        else if(arah==3){
            laser(i, j+1, 2);
        }
    }
    else if(papan[i][j]=='.'){
        if(arah==0){
            papan[i][j]='-';
            laser(i, j-1, arah);
        }
        else if(arah==1){ 
            papan[i][j]='|'; 
            laser(i-1, j, arah); 
        }
        else if(arah==2){ 
            papan[i][j]='-'; 
            laser(i, j+1, arah); 
        }
        else if(arah==3){ 
            papan[i][j]='|'; 
            laser(i+1, j, arah);  
        }
    }
    else if(papan[i][j]=='|') {
        if(arah==0){ 
            papan[i][j] = '+'; 
            laser(i, j-1, arah); 
        }
        else if(arah==1){ 
            laser(i-1, j, arah);  
        }
        else if(arah==2){ 
            papan[i][j] = '+'; 
            laser(i, j+1, arah); 
        }
        else if(arah==3){ 
            laser(i+1, j, arah);  
        }
    }
    else if(papan[i][j]=='-') {
        if(arah==0){ 
            laser(i, j-1, arah); 
        }
        else if(arah==1){ 
            papan[i][j]='+'; 
            laser(i-1, j, arah); 
        }
        else if(arah==2){ 
            laser(i, j+1, arah); 
        }
        else if(arah==3){ 
            papan[i][j]='+'; 
            laser(i+1, j, arah); 
        }
    }
    else if(papan[i][j]=='+') {
        if(arah==0){ 
            laser(i, j-1, arah);  
        }
        else if(arah==1){ 
            laser(i-1, j, arah); 
        }
        else if(arah==2){ 
            laser(i, j+1, arah); 
        }
        else if(arah==3){ 
            laser(i+1, j, arah);  
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", papan[i]);
    }
    char a[10];
    int x;
    scanf("%s %d", a, &x);
    if(!strcmp(a, "atas")) laser(0, x, 3);
    else if(!strcmp(a, "bawah")) laser(n-1, x, 1);
    else if(!strcmp(a, "kiri")) laser(x, 0, 2);
    else if(!strcmp(a, "kanan")) laser(x, n-1, 0);
    for(int i=0; i<n; i++){
        printf("%s\n", papan[i]);
    }
    return 0;
}