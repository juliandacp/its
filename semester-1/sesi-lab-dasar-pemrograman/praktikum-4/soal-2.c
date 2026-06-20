#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char name[50];
    int priority;
}task;

int main(){
    task *taskPtr=NULL;
    int index=0;
    while(1){
        char cmd[20];
        scanf("%s", cmd);
        if(!strcmp(cmd, "EXIT")){
            break;
        }else if(!strcmp(cmd, "ADD")){
            taskPtr=(task*)realloc(taskPtr, (index+1)*sizeof(task));
            scanf(" %s %d", taskPtr[index].name, &taskPtr[index].priority);
            printf("%s %d is added\n", taskPtr[index].name, taskPtr[index].priority);
            index++;
        }else if(!strcmp(cmd, "CHECK")){
            int id;
            scanf(" %d", &id);
            if(id<0 || id>=index) printf("Task at ID %d is empty\n", id);
            else if(strcmp(taskPtr[id].name, "[deleted]")==0) printf("Task at ID %d is empty\n", id);
            else printf("%s %d\n", taskPtr[id].name, taskPtr[id].priority);
        }else if(!strcmp(cmd, "LIST")){
            printf("TO DO LIST:\n");
            for(int i=0; i<index; i++){
                if(strcmp(taskPtr[i].name, "[deleted]")!=0) printf("%s %d\n", taskPtr[i].name, taskPtr[i].priority);
            }
        }else if(!strcmp(cmd, "CLEAR")){
            int id;
            scanf(" %d", &id);
            if(id>=0 && id<index){
                if(strcmp(taskPtr[id].name, "[deleted]")==0) printf("Task [deleted] is cleared\n");
                else{
                    printf("Task %s is cleared\n", taskPtr[id].name);
                    strcpy(taskPtr[id].name, "[deleted]");
                }
            }
        }
    }    
    free(taskPtr);
    return 0;
}