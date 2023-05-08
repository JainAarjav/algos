#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void innit(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=malloc(size*sizeof(int));
}

void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }

}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->rear==q->front)
    {
        return x;
    }
    else
    {
        q->front++;
        return q->Q[q->front];
    }
}
int isEmpty(struct Queue *q)
{
    return q->front==q->rear;
}
void BFS(int G[][7],int start ,int n)
{
    int i=start;
    struct Queue q;
    innit(&q,7);
    int visited[7]={0};
    printf("%d",i);
    visited[i]=1;
    enqueue(&q,i);
    while(!isEmpty(&q))
    {
        i=dequeue(&q);
        for(int j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                printf("%d",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
}


void DFS(int G[][7],int start,int n)
{
    static int visited[7]={0};
    if(visited[start]==0)
    {
        visited[start]=1;
        printf("%d",start);
        for(int j=1;j<n;j++)
        {
            if(G[start][j]==1 && visited[j]==0)
            {
                DFS(G,j,n);
            }
        }
    }
}
int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
             {0,0,1,1,0,0,0},
             {0,1,0,0,1,0,0},
             {0,1,0,0,1,0,0},
             {0,0,1,1,0,1,1},
             {0,0,0,0,1,0,0},
{0,0,0,0,1,0,0}};

// BFS(G,7,7);
DFS(G,1,7);
return 0;
}