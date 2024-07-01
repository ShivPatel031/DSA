// Stack using Linked list

class Node
{
    public:
    int data;
    Node *next;
    
    Node(int x)
    {
      data=x;
      next=null;
    }
};

class Stack
{
    Node *top;
    int size();
    
    public:

    Stack()
    {
      top=NULL;
      size=0; 
    }
    
    void push(int x)
    {
      Node *temp = new Node(x);
      if(temp==NULL)
      {
        cout<<"Stack is overflow"<<endl;
        return;
      }
    
      temp->next = top;
      top=temp;
      size++;
    }


    void pop()
    {
      if(top==NULL)
      {
        cout<<"Stack is Underflow"<<endl;
        return;
      }
    
      Node *temp = top;
      top=top->next;
      delete temp; 
      size--;
    }


    int peek()
    {
      if(top==NULL)
      {
        cout<<"Stack is empty"<<endl;
        return -1;
      }
    
      return top->data;
    }


    bool isEmpty()
    {
      return top==NULL; 
    }


    bool isSize()
    {
      return size;
    }
};
