// create Max Heap using Array

class MaxHeap
{
  int *arr;
  int size;
  int totalSize;

  public:
  
  MaxHeap(int n)
  {
    arr =  new int[n];
    size=0;
    totalSize=n;
  }

  void insertInHeap(int val)
  {
      if(size==totalSize)
      {
        cout<<"Heap is overflow"<<endl;
        return;
      }
    
      arr[size]=val;
      int index=size;
      size++;
    
      // stap up if node is greater then parent node
      while(index>0 && arr[index]>arr[(index-1)/2])
      {
        swap(arr[index],arr[(index-1)/2]);
        index=(index-1)/2;
      }
  }

  void deleteInHeap()
  {
      if(size==0)
      {
        cout<<"Heap is underflow"<<endl;
        return;
      }
  
      swap(arr[size-1],arr[0]);
      size--;

      if(size==0) return;
  
      heapify(0);
  }

  void heapify(int index)
  {
      int largest = index;
      int left = 2*index+1;
      int right = 2*index+2;
    
      if(left < size && arr[left]>arr[largest])
      {
        largest = left;
      }
    
      if(right<size && arr[right]>arr[largest])
      {
        largest=right;
      }
    
      if(largest != index)
      {
        swap(arr[index],arr[largest]);
        heapify(largest);
      }
  }
};
