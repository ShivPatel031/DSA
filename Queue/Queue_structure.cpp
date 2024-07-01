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

// Circular Queue Structure

class CQueue
{
    int *arr;
    int front,rear,size;
    public:

    CQueue(int n)
    {
      arr=new int[n];
      front=-1;
      rear=-1;
      size=n;
    }
    
    bool isEmpty()
    {
      return front==-1 || front+1=rear;
    }
    
    bool isFull()
    {
      return (front==size-1 && rear==0) || (front+1==rear);
    }
    
    void push(int x)
    {
      if(isFull())
      {
        cout<<"CQueue is Overflow"<<endl;
        return;
      }
      
      if(isEmpty()){rear++;}

      if(front==size-1 && rear!=0)
      {
          front=-1;
      }
      
      front++;
      arr[front]=x;
    }
    
    int pop()
    {
      if(isEmpty() || front+1==rear)
      {
        cout<<"CQueue is Underflow"<<endl;
        return -1;
      }
        
      int element = arr[rear];

      if(rear==size-1 && front !=0)
      {
          rear=-1;
      }
      rear++;
      return element;
    }
    
    void resetQueue()
    {
      front=-1;
      rear=-1;
    }
};

