#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int* ar,int n,int data);
int binarySearch(int* ar,int n,int data);
int interpolation_search(int *ar,int n,int data);
int uniformSet(int *ar,int n);

int file_write();
int* fileRead(int *arr,int n);

int main()
{
    int n,i,ch,data;
    int *arr;

    clock_t start, end;
    long cpu_time_used;

    n=file_write();
    arr = (int*)malloc(n*sizeof(int));


    //for(i=0;i<n;i++)          //printing the random array taken
    //    printf("%d ", arr[i]);

    do{
        arr = fileRead(arr,n);
        printf("\n\n1) Linear search\n2) Binary search\n3) Interpolation search\n4) Exit\n");
        scanf("%d",&ch);
        printf("\nenter data you want to search\n");
        scanf("%d",&data);
        printf("\n");

        start = clock();

        switch(ch)
        {
        case 1:
            linearSearch(arr,n,data);
            break;
        case 2:
            binarySearch(arr,n,data);
            break;
        case 3:
            interpolation_search(arr,n,data);
            break;
        case 4:
            ch=4;
            break;
        }

        end = clock();
        cpu_time_used = ((double) (end - start)) / (double)(CLOCKS_PER_SEC/1000);
        printf("\nalgorithm took %f seconds to execute\n\n", cpu_time_used);

    }while(ch!=4);
    free(arr);
    return 0;
}

int linearSearch(int* ar,int n,int data)
{
    int i,counter=0;
    for(i=0;i<n;i++)
    {
        counter++;
        if(ar[i]==data)
        {
            printf("data found at position %d\n",i);
            printf("counter - %d",counter);
            return i;
        }
    }
    printf("data not found");
    return 0;
}

int binarySearch(int* ar,int n,int data)
{
    int i=0,low,high,k,counter=0;
    QuickSort(ar,0,n-1);
    low=0;
    high=n;
    while(high>low)
    {
        counter++;
        k=(high-low)/2;
        k=low+k;
        if(ar[k]==data)
        {
            printf("data found at position %d\n",k);
            printf("counter - %d",counter);
            return k;
        }
        else if(ar[k]>data)
            high=k;
        else
            low=k+1;
    }
    printf("data not found\n");
    return 0;
}

int interpolation_search(int *ar,int n,int data)
{
    int check,low,high,pos,i,counter=0;
    low=0;
    high=n-1;
    QuickSort(ar,0,n-1);
    //for(i=0;i<n;i++)
    //    printf("%d ",ar[i]);  //for printing sorted data
    printf("\n");
    check=uniformSet(ar,n);
    if(check==1)
    {
        printf("uniform data\n");
        while (low<=high && data>=ar[low] && data<=ar[high])
        {
            counter++;
            if (low==high)
            {
                if (ar[low] == data)
                {
                    printf("data found at position %d\n",pos);
                    printf("counter - %d",counter);
                    return low;
                }
                printf("data not found\n");
                return -1;
            }
            int pos=(low + ((high - low)/(ar[high] - ar[low])) * (data - ar[low]));
            if (ar[pos] == data)
            {
                printf("data found at position %d\n",pos);
                printf("counter - %d",counter);
                return pos;
            }
            if (ar[pos] < data)
                low = pos + 1;
            else
                high = pos - 1;
        }
    printf("data not found at position %d\n");
    return -1;
    }
    else
    {
        printf("non uniform data\n");
        while (low<=high && data>=ar[low] && data<=ar[high])
        {
            counter++;
            if (low==high)
            {
                if (ar[low] == data)
                {
                    printf("data found at position %d\n",pos);
                    printf("counter - %d",counter);
                    return low;
                }
                printf("data not found\n");
                return -1;
            }
            int pos=(low + ((high - low)/(ar[high] - ar[low])) * (data - ar[low]));
            if (ar[pos] == data)
            {
                printf("data found at position %d\n",pos);
                printf("counter - %d",counter);
                return pos;
            }
            if (ar[pos] < data)
                low = pos + 1;
            else
                high = pos - 1;
        }
        printf("data not found\n");
        return -1;
    }
    return 0;

}
int uniformSet(int *ar,int n)
{
    int i;
    for(i=2;i<n;i++)
        if(ar[i]-ar[i-1]!=ar[i-1]-ar[i-2])
            return 0;
    return 1;
}

