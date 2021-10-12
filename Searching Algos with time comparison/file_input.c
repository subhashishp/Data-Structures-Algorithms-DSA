#include <stdio.h>


int file_write()
{
    int n,i,r,t;
    int *arr;

    FILE *fptr;
    fptr = fopen("./File/cases.txt","w");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("enter size n\n");
    scanf("%d",&n);
    n=5*n;
    arr= (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        arr[i]=i;

    srand(time(NULL));

    for(i=n;i>0;i--)
    {
        r=rand()%n;
        t=arr[i-1];
        arr[i-1]=arr[r];
        arr[r]=t;
    }

    for(i=0;i<n;i++)        //writing in file
    {
        //arr[i]=rand()%10;
        fprintf(fptr,"%d ",arr[i]);
        //printf("%d ",*(arr+i));
    }
    //fprintf(fptr,"%d ",105);     //for non-uniform data
    fclose(fptr);
    free(arr);
    return n/5;
}
