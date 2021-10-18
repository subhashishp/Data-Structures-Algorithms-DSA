void insertion_sort(int* arr,int n)
{
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=arr[i];
        while(j>=0 && temp<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
