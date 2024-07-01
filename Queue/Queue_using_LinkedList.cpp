// Queue implementation using Linked list

class Node
{
    public:
    int data;
    Node *next;
    
    Node(int x)
    {
      data=x;
      nexxt=null;
    }
};

class Queue
{
    Node *front,*rear;

    public:

    Queue()
    {
      front=NULL;
      rear=NULL;
    }
  
    bool isEmpty()
    {
      return front==-1;
    }
    
    void push(int x)
    {
      if(isEmpty())
      {
        front=new Node(x);
        rear=front;
      }
      else
      {
        front->next = new Node(x);
        front=front->next;
      }
      
    }
    
    void pop()
    {
      if(isEmpty())
      {
        cout<<"Queue is Underflow"<<endl;
        return -1;
      }
    
      Node *temp=rear;
      rear=rear->next;
      free(temp);
      
    }

    int fornt()
    {
      if(isEmpty())
      {
        return -1;
      }

      return front->data;
    }
};
