// Queue Structure

class Queue
{
    int *arr;
    int front,rear,size;
    public:

    Queue(int n)
    {
      arr=new int[n];
      front=-1;
      rear=-1;
      size=n;
    }
    
    bool isEmpty()
    {
      return front==-1;
    }
    
    bool isFull()
    {
      return front==size-1;
    }
    
    void push(int x)
    {
      if(isFull())
      {
        cout<<"Queue is Overflow"<<endl;
        return;
      }
      
      if(isEmpty()){rear++;}
      
      front++;
      arr[front]=x;
    }
    
    int pop()
    {
      if(isEmpty() || front < rear)
      {
        cout<<"Queue is Underflow"<<endl;
        return -1;
      }
    
      int element = arr[rear];
      rear++;
      return element;
    }
    
    void resetQueue()
    {
      front=-1;
      rear=-1;
    }
};
