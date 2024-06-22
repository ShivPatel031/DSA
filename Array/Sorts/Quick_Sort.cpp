// Quick Sort

int partition (vector<int> &arr,int left,int right)
{
    int pos=left;
  
    for(int i = left;i<=right;i++)
    {
        if(arr[i]<=arr[right])
        {
            swap(arr[i],arr[pos]);
            pos++;
        }
    }

    return pos-1;
    
}

void QuickSort(vector<int> &arr,int left,int right)
{
    if(left>=right)
    {
        return;
    }
  
    int pivot = partition(arr,left,right);
    QuickSort(arr,left,pivot-1);
    QuickSort(arr,pivot+1,right);
}
