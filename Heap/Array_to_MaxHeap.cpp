// Array to Max Heap

void heapify(int arr[],int index,int n)
{
  int largest = index;
  int left = index*2+1;
  int right = index*2+2;

  if(left < n && arr[largest]<arr[left])
  {
    largest = left;
  }

  if(right<n && arr[largest]<arr[right])
  {
    largest = right;
  }

  if(largest != index)
  {  
      swap(arr[largest],arr[index]);
      heapify(arr,largest,n);
  }
}

void buildMaxHeap(int arr[],int n)
{
  for(int i = n/2-1,i>=0;i--)
  {
    heapify(arr,i,n);
  }
}

// to make min heap
void heapify(int arr[],int index,int n)
{
  int largest = index;
  int left = index*2+1;
  int right = index*2+2;

  // just change condtion
  if(left < n && arr[largest]>arr[left])
  {
    largest = left;
  }

  // just change condtion
  if(right<n && arr[largest]>arr[right])
  {
    largest = right;
  }

  if(largest != index)
  {  
      swap(arr[largest],arr[index]);
      heapify(arr,largest,n);
  }
}
