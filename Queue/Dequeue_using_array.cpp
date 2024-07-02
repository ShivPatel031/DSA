// Dequeue implementation using array

class Dequeue
{
    int *arr;
    int fornt,back;
    int size;

    public:

    Dequeue(int n)
    {
      arr=new int[n];
      front=back=-1;
      size=n;
    }
    
    bool isEmpty()
    {
      return front==-1;
    }
    
    bool isFull()
    {
      return (back+1) % size == front;
    }
    
    void push_front(int x)
    {
      if(front==-1)
      {
        front=back=0;
        arr[front]=x;
      } 
      else if(ifFull())
      {
        cout<<"Dequeue is overflow";
      }
      else{
        front=(front-1+size)%size;
        arr[front]=x;
      }
        
    }
    
    void push_back(int x)
    {
      if(front==-1)
      {
        front=back=0;
        arr[front]=x;
      } 
      else if(isFull())
      {
        cout<<"Dequeue is overflow";
      }
      else{
        back=(back+1)%size;
        arr[back]=x;
      }   
    }
    
    void pop_front()
    {
      if(isEmpty())
      {
        cout<<"Dequeue is underflow";
      }
      else
      {
        if(front==back)
        {
          back=front=-1;
        }
        else
        {
          front=(front+1)%size;
        }
      }
    }
    
    void pop_back()
    {
      if(isEmpty())
      {
        cout<<"Dequeue is underflow";
      }
      else
      {
        if(back==front)
        {
          back=front=-1;
        }
        else
        {
          back=(back-1+size)%size;
        }
      }
    }

    int start()
    {
      if(isEmpty())
      {
        return -1;
      }
      else
      {
        return arr[front];
      }
    }

    int end()
    {
      if(isEmpty())
      {
        return -1;
      }
      else
      {
        return arr[back];
      }
    }

};
