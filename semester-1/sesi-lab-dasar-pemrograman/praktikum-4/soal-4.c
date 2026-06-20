#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size=0;
typedef struct{
    int size;
    int index;
    int *array;
}Data;

void free_data(Data *data, int size){
    if(!data) return;
    for(int i=0; i<size; i++){
        free(data[i].array);
    }
    free(data);
}

void resize(Data *data, int idx){
    if(data[idx].size==0){
        data[idx].size=2;
        data[idx].array=(int*)malloc(data[idx].size*sizeof(int));
    }else{
        data[idx].size*=2;
        data[idx].array=(int*)realloc(data[idx].array, data[idx].size*sizeof(int));
    }
}

void insert(Data **data_ptr, int a, int b){
    int max_idx=(a>b)?a:b;
    if(max_idx>=size){
        int old_size=size;
        int new_size=max_idx+1;
        Data *new_array=(Data*)realloc(*data_ptr, new_size*sizeof(Data));
        if(!new_array){
            free_data(*data_ptr, old_size);
            exit(1);
        }
        for(int i=old_size; i<new_size; i++){
            new_array[i].size=0;
            new_array[i].index=0;
            new_array[i].array=NULL;
        }
        *data_ptr=new_array;
        size=new_size;
    }
    if((*data_ptr)[a].index>=(*data_ptr)[a].size) resize(*data_ptr, a);
    if((*data_ptr)[b].index>=(*data_ptr)[b].size) resize(*data_ptr, b);
    (*data_ptr)[a].array[(*data_ptr)[a].index++]=b;
    (*data_ptr)[b].array[(*data_ptr)[b].index++]=a;
}

void print(Data *data){
    for(int i=1; i<size; i++){
        if(data[i].index==0) continue;
        printf("Pulau %d: ", i);
        for(int j=0; j<data[i].index; j++){
            printf("%d", data[i].array[j]);
            if(j<data[i].index-1) printf(" ");
        }
        printf("\n");
    }
}

int main(){
    Data *data=NULL;
    int a, b;
    while(scanf("%d %d", &a, &b)==2){
        insert(&data, a, b);
    }
    print(data);
    free_data(data, size);
    return 0;
}