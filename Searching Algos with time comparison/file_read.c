#include <stdio.h>

int* fileRead(int *arr,int n)
{
    int i;
    FILE *fptr;
    printf("\nrandom array taken\n");
    fptr = fopen("./File/cases.txt","r");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    for(i=0;i<n;i++)        //reading from file
        fscanf(fptr,"%d",&arr[i]);
    return arr;
}
