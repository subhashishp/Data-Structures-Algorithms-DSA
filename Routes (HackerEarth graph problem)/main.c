//This is zero based indexed code
//start input node from 0;

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct vertex
{
    int vertex_val;
    int fare;
    float time;
    struct vertex *next;
};
void Dijkstra_Algorithm(struct vertex **head,int source,int destination,int V,int K);
void printPath(int** parent,int source, int dest);

int main()
{
    int V,src,dstn,i,j,connected,check=0,edges;
    int K,time;
    printf("enter K\n");
    scanf("%d",&K);

    printf("Enter number of vertices and edges\n");
    scanf("%d%d",&V,&edges);
    struct vertex **adjacency_list_head=(struct vertex **)malloc(V*sizeof(struct vertex *));
    struct vertex *temp,*end;
    for(i=0;i<V;i++)
    {
        printf("enter number of connected vertices to %d\n",i);
        scanf("%d",&connected);
        check=0;
        printf("enter connected vertex and fare and time with vertex %d\n",i);
        for(j=0;j<connected;j++)
        {
            temp=(struct vertex *)malloc(sizeof(struct vertex));
            temp->next=NULL;
            scanf("%d %d %f",&temp->vertex_val,&temp->fare,&temp->time);
            if(check==0)
            {
                adjacency_list_head[i]=temp;
                end=temp;
                check=1;
            }
            else
            {
                end->next=temp;
                end=temp;
            }
        }
    }
    printf("Enter source and destination vertex\n");
    scanf("%d %d",&src,&dstn);
    Dijkstra_Algorithm(adjacency_list_head,src,dstn,V,K);
    return 0;
}

void Dijkstra_Algorithm(struct vertex **head,int source,int destination,int V,int K)
{
    struct vertex *temp;
    int i,j,min=INT_MAX,save=0;

    int **arr=(int**)malloc(3*sizeof(int*));
    for(i=0;i<3;i++)
        arr[i]=(int*)malloc(V*sizeof(int));
    for(i=0;i<V;i++)
    {
        arr[0][i]=INT_MAX;                      //i=0- distance
        arr[1][i]=-1;                           //i=1- parent_node (-1) no parent node yet
        arr[2][i]=0;                            //i=2- visited 0=not blocked 1=blocked
    }
    arr[0][source]=0;
    for(i=0;i<V;i++)
    {
        min=INT_MAX;
        for(j=0;j<V;j++)
        {
            if(arr[0][j]<min && arr[2][j]==0)
            {
                save=j;
                min=arr[0][j];
            }
        }
        j=save;
        arr[2][j]=1;
        temp=head[j];
        while(temp!=NULL)
        {
            if((arr[0][save]+temp->fare) < arr[0][temp->vertex_val] && arr[2][temp->vertex_val]==0)
            {
                arr[0][temp->vertex_val]=arr[0][save]+temp->fare+(temp->time*K)+K;
                arr[1][temp->vertex_val]=save;
            }
            temp=temp->next;
        }
    }
    arr[0][destination]-=K;
    if(arr[0][destination]!=INT_MAX)
        printf("\nMinimum cost from source to destination - %d\n",arr[0][destination]);
    else
        printf("Error\n");
    i=destination;
    printf("\nPath from source to destination\n");
    printPath(arr,source,destination);

}

void printPath(int** parent,int source, int dest)
{
  if(source==dest){
    printf("%d",(source+1));
    return;
  }
  printPath(parent,source,parent[1][dest]);
  printf("-->%d",(dest+1));
}
