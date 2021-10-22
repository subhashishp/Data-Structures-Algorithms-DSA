#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* BubbleSort(int* ar,int n);
int* ModifiedBubbleSort(int* ar,int n);
int* CocktailshakerSort(int* ar,int n);
int* SelectionSort(int* ar,int n);
void QuickSort(int* ar,int low,int high);
int partition(int* ar,int low,int high);


int main()
{
    int ch,i,x=0,n=10,r,t=0;
    int *arr;

    clock_t start, end;
    double cpu_time_used;

    FILE *fptr;
    fptr = fopen("./File/cases.txt","w");
    if(fptr == NULL)
    {
       printf("Error!");
       exit(1);
    }

    printf("enter size n\n");
    scanf("%d",&n);

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
    fclose(fptr);
    do
    {
        printf("\nrandom array taken\n");

        fptr = fopen("./File/cases.txt","r");
        if(fptr == NULL)
        {
            printf("Error!");
            exit(1);
        }
        for(i=0;i<n;i++)        //reading from file
            fscanf(fptr,"%d",&arr[i]);

        //for(i=0;i<n;i++)      //printing the random array
        //    printf("%d ",*(arr+i));
        printf("\n");
        printf("\n1) Bubble sort\n2) Modified Bubble Sort\n3) Cocktail shaker sort\n4) Selection Sort\n5) Quick Sort.\n6)exit\n");
        scanf("%d",&ch);
        start = clock();
        switch(ch)
        {
        case 1:
            arr = BubbleSort(arr,n);
            break;
        case 2:
            arr = ModifiedBubbleSort(arr,n);
            break;
        case 3:
            arr = CocktailshakerSort(arr,n);
            break;
        case 4:
            arr = SelectionSort(arr,n);
            break;
        case 5:
            QuickSort(arr,0,(n-1));
            break;
        case 6:
            x=1;
            break;
        }

        end = clock();
        cpu_time_used = ((double) (end - start)) / (double)CLOCKS_PER_SEC;
        printf("array sorted\n");
        printf("algorithm took %f seconds to execute\n\n", cpu_time_used);

        //for(i=0;i<n;i++)      //printing sorted array
        //    printf("%d ",arr[i]);
        printf("\n");
        fclose(fptr);
    }while(x!=1);
    return 0;
}

int* BubbleSort(int* ar,int n)
{
    int i,j,swap;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                swap=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=swap;
            }
        }
    }
    return ar;
}

int* ModifiedBubbleSort(int* ar,int n)
{
    int i,j,swap,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                swap=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=swap;
                flag = 1;
            }
        }
        if(flag==0)
        {
            printf("break %d \n",i);
            break;
        }
    }
    return ar;
}

int* CocktailshakerSort(int* ar,int n)
{
    int i,j,swap,k=n,x=0,flag=0;
    for(i=0;i<(n-1)/2;i++)
    {
        flag=0;
        for(j=x;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                swap=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=swap;
                flag = 1;
            }
        }
        x++;
        k--;
        for(j=k;j>0;j--)
        {
            if(ar[j]<ar[j-1])
            {
                swap=ar[j];
                ar[j]=ar[j-1];
                ar[j-1]=swap;
            }
        }
        if(flag == 0)
        {
            printf("break %d\n",i);
            break;
        }
    }
    return ar;
}

int* SelectionSort(int* ar,int n)
{
    int i,j,swap,min=-50,pos;
    for(i=0;i<n-1;i++)
    {
        min = ar[i];
        pos = i;
        for(j=i+1;j<n;j++)
        {
            if(ar[j] < min)
            {
                min = ar[j];
                pos = j;
            }
        }
        ar[pos]=ar[i];
        ar[i]=min;
    }
    return ar;
}

void QuickSort(int* ar,int low,int high)
{
    int par;
    if(low <= high)
    {
        par = partition(ar,low,high);
        QuickSort(ar,low,(par-1));
        QuickSort(ar,(par+1),high);
    }
}

int partition(int* ar,int low,int high)
{
    int pivot,i,j,swap;
    pivot = ar[high];
    i = (low-1);
    for(j=low;j<high;j++)
    {
        if(ar[j] <= pivot)
        {
            i++;
            swap = ar[i];
            ar[i] = ar[j];
            ar[j] = swap;
        }
    }
    i++;
    swap = ar[i];
    ar[i] = pivot;
    ar[high] = swap;
    return i;
}

