#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int file_write();
int* fileRead(int *arr,int n);
void QuickSort(int* ar,int low,int high);
void merge(int* arr,int low,int mid,int high);
void merge_sort(int* arr,int low,int high);
void insertion_sort(int* arr,int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);


int main()
{
    int n,i,ch,data;
    int *arr;

    clock_t start, end;
    double cpu_time_used;

    n=file_write();
    arr = (int*)malloc(n*sizeof(int));

    do{
        arr = fileRead(arr,n);
        printf("\n\n1) Quick Sort\n2) Merge sort\n3) Insertion sort\n4) Heap sort\n5) exit\n");
        scanf("%d",&ch);
        printf("\n");

        start = clock();
        switch(ch)
        {
        case 1:
            QuickSort(arr,0,n-1);
            break;
        case 2:
            merge_sort(arr,0,n-1);
            break;
        case 3:
            insertion_sort(arr,n);
            break;
        case 4:
            heapSort(arr,n);
            ch=4;
            break;
        case 5:
            ch=5;
            break;
        }

        // for printing array
        //for(i=0;i<n;i++)
        //    printf("%d ",arr[i]);

        end = clock();
        cpu_time_used = ((double) (end - start)) / (double)CLOCKS_PER_SEC;
        printf("\narray sorted\n");
        printf("\nalgorithm took %f seconds to execute\n\n", cpu_time_used);

    }while(ch!=5);
    free(arr);
    return 0;
}
