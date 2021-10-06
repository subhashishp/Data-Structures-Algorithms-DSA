#include <stdio.h>
#include <stdlib.h>


struct vertex
{
    int vertex_val;
    int cost_paid;
    struct vertex *next;
};

void prims(struct vertex **head,int V);

int main()
{
    int connected,check,V,i,j;
    printf("Enter number of vertices\n");
    scanf("%d",&V);
    struct vertex **adjacency_list_head=(struct vertex **)malloc(V*sizeof(struct vertex *));
    struct vertex *temp,*end;

    //Creating the graph using adjacency list
    for(i=0;i<V;i++)
    {
        printf("enter number of connected vertices to %d\n",i);
        scanf("%d",&connected);
        check=0;
        printf("enter connected vertex and cost with vertex %d\n",i);
        for(j=0;j<connected;j++)
        {
            temp=(struct vertex *)malloc(sizeof(struct vertex));
            temp->next=NULL;
            scanf("%d %d",&temp->vertex_val,&temp->cost_paid);
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

    //Calculating MST
    prims(adjacency_list_head,V);
    return 0;
}

void prims(struct vertex **head,int V)
{
    struct vertex *temp;
    int MST_sum=0,i,j,min,temp_v;

    //array to calculate MST
    int **arr=(int**)malloc(3*sizeof(int*));
    for(i=0;i<3;i++)
        arr[i]=(int*)malloc(V*sizeof(int));

    //preprocessing array
    for(i=0;i<V;i++)
    {
        arr[0][i]=INT_MAX;                      //i=0- cost
        arr[1][i]=-1;                           //i=1- parent_node (-1) no parent node yet
        arr[2][i]=0;                            //i=2- 0-not visited 1-visited
    }

    //calculating MST
    i=0;
    arr[0][0]=0;
    //printf("1st node  %d",*head[i]);
    for(i=0;i<V;i++)
    {
        min = INT_MAX;
        for(j=0;j<V;j++)
        {
            if(arr[0][j]<min && arr[2][j]==0)
            {
                min=arr[0][j];
                temp_v=j;
            }
        }
        j=temp_v;
        arr[2][j]=1;
        temp=head[j];
        while(temp)
        {
            if(arr[0][temp->vertex_val]>temp->cost_paid && arr[2][temp->vertex_val]==0)
            {
                arr[0][temp->vertex_val]=temp->cost_paid;
                arr[1][temp->vertex_val]=temp_v;
            }
            temp=temp->next;
        }
    }

    printf("printing arr values\n\n");
    for(i=0;i<V;i++)
    {
         printf("%d ",arr[0][i]);
         MST_sum+=arr[0][i];
    }
        printf("%d ",arr[0][i]);
    printf("\n");
    for(i=0;i<V;i++)
        printf("%d ",arr[1][i]);
    printf("\n");
    for(i=0;i<V;i++)
        printf("%d ",arr[2][i]);
    printf("\n");
    printf("MST - %d\n",MST_sum);
}
