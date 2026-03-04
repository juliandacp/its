#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

typedef struct{
    int x;
    int y;
    int dist;
}Node;

typedef struct{
    Node data[105];
    int front;
    int rear;
}Queue;

void isi_Queue(Queue *q){
    (*q).front=0;
    (*q).rear=0;
}

int empty(Queue q){
    return q.front==q.rear;
}

void enqueue(Queue *q, Node node){
    (*q).data[(*q).rear]=node;
    (*q).rear=(*q).rear+1;
}

Node dequeue(Queue *q){
    Node node=(*q).data[(*q).front];
    (*q).front=(*q).front+1;
    return node;
}

int main(){
    int n;
    scanf("%d", &n);
    int maze[n+5][n+5];
    int visited[n+5][n+5];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    int dx[4]={-1, 0, 1, 0};
    int dy[4]={0, 1, 0, -1};
    Queue q;
    isi_Queue(&q);
    Node start;
    start.x=0;
    start.y=0;
    start.dist=0;
    enqueue(&q, start);
    visited[0][0]=1;
    int min_distance=-1;
    int found=0;
    while(empty(q)==0){
        Node current=dequeue(&q);
        if(current.x==n-1 && current.y==n-1){
            min_distance=current.dist;
            found=1;
            break;
        }
        for(int i=0; i<4; i++){
            int new_x=current.x+dx[i];
            int new_y=current.y+dy[i];
            if(new_x>=0 && new_x<n && new_y>=0 && new_y<n){
                if(maze[new_x][new_y]==1 && visited[new_x][new_y]==0){
                    visited[new_x][new_y]=1;
                    Node next;
                    next.x=new_x;
                    next.y=new_y;
                    next.dist=current.dist+1;
                    enqueue(&q, next);
                }
            }
        }
    }
    if(found==1) printf("%d menit doang\n", min_distance);
    else printf("Dahlah gajadi balik\n");
    return 0;
}