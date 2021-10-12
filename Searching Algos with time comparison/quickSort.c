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

