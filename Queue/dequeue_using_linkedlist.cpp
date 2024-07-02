// dequeue implementation using linked list

class Node
{
    public:
    int data;
    Node *next,*prev;
    
    Node(int x)
    {
      data = x;
      next=prev=nullptr;
    }
};

class Dequeue
{
    Node *front,*rear;

    public:
    
    Dequeue()
    {
      front=nullptr;
      rear=nullptr;
    }

    bool isEmpty()
    {
      return  front==nullptr;
    }  
    
    void push_front(int x)
    {
      if(front==nullptr)
      {
        front=rear=new Node(x);
      }
      else
      {
        Node *temp = new Node(x);
        temp->next=front;
        front->prev=temp;
        front=temp;
      }
    }
    
    void push_back(int x)
    {
      if(front==nullptr)
      {
        front=rear=new Node(x);
      }
      else
      {
        Node *temp = new Node(x);
        temp->prev=rear;
        rear->next=temp;
        rear=temp;
      }
    }
    
    void pop_front()
    {
      if(front==nullptr)
      {
        cout<<"Dequeue is empty";
      }
      else
      {
        Node *temp = front;
        front=front->next;
        delete temp;
        if(front)
        {
          front->prev=nullptr;
        }
        else
        {
          rear=nullptr;
        }
      }
    }
    
    void pop_back()
    {
      if(rear==nullptr)
      {
        cout<<"Dequeue is empty";
      }
      else
      {
        Node *temp = rear;
        rear=rear->prev;
        delete temp;
        if(rear)
        {
          rear->next=nullptr;
        }
        else
        {
          front=nullptr; 
        }
      }
    }
    
    int start()
    {
      if(front==nullptr)
      {
        return -1;
      }
      else
      {
        return front->data;
      }
    }
    
    int end()
    {
      if(rear==nullptr)
      {
        return -1;
      }
      else
      {
        return rear->data;
      }
    }
};

