#include<stdio.h>
#include<math.h>

float mse(float arr1[], float arr2[], int n){
    float sum1=0.0;
    float tot1=0.0;
    for(int i=0; i<n; i++){
        tot1=(arr1[i]-arr2[i])*(arr1[i]-arr2[i]);
        sum1+=tot1;
    }
    return sum1/(float)n;
}

float mae(float arr1[], float arr2[], int n){
    float sum2=0.0;
    float tot2=0.0;
    for(int i=0; i<n; i++){
        tot2=fabs(arr1[i]-arr2[i]);
        sum2+=tot2;
    }
    return sum2/(float)n;
}

float mape(float arr1[], float arr2[], int n){
    float sum4=0.0;
    float tot4=0.0;
    for(int i=0; i<n; i++){
        tot4=fabs(arr1[i]-arr2[i])/fabs(arr1[i]);
        sum4+=tot4;
    }
    return sum4/(float)n*100;
}

int main(){
    int n;
    int cek=1;
    scanf("%d", &n);
    float arr1[n+5];
    float arr2[n+5];
    for(int i=0; i<n; i++){
        scanf("%f", &arr1[i]);
        if(arr1[i]==0) cek=0;
    }
    for(int i=0; i<n; i++){
        scanf("%f", &arr2[i]);
    }
    float hasil1=mse(arr1, arr2, n);
    float hasil2=mae(arr1, arr2, n);
    float hasil3=sqrt(hasil1);
    float hasil4;
    if(cek==1) hasil4=mape(arr1, arr2, n);
    printf("MSE: %.2f, MAE: %.2f, RMSE: %.2f, MAPE: %.2f\n", hasil1, hasil2, hasil3, hasil4);
    return 0;
}

