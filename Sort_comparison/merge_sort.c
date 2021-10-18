void merge(int* arr,int low,int mid,int high)
{
    int i,j,k,n1,n2;
    n1=mid - low + 1;
    n2=high - mid;
    //int arr_low[n1],arr_high[n2];
    int *arr_low = (int*)malloc(n1*sizeof(int));
    int *arr_high = (int*)malloc(n2*sizeof(int));
    for(i=0;i<n1;i++)
        arr_low[i]=arr[low+i];
    for(i=0;i<n2;i++)
        arr_high[i]=arr[mid+1+i];
    i=0;
    j=0;
    k=low;
    while (i < n1 && j < n2)
    {
        if (arr_low[i] <= arr_high[j])
        {
            arr[k] = arr_low[i];
            i++;
        }
        else
        {
            arr[k] = arr_high[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = arr_low[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = arr_high[j];
        j++;
        k++;
    }
}
void merge_sort(int* arr,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=low + (high - low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
