// Stack implementation
class Stack
{
    int *arr;
    int top,size;

    public:

    Stack(int n)
    {
      arr=new int[n];
      size=n;
      top=-1;
    }
    
    bool isEmpty()
    {
      return top==-1;
    }
    
    void push(int x)
    {
      if(top==size-1)
      {
        cout<<"Stack is overflow"<<endl;
        return;
      }
      top++;
      arr[top]=x;
    }
    
    void pop()
    {
      if(top==-1)
      {
        cout<<"Stack is Underflow"<<endl;
        return;
      }
      top--;
    }
    
    int peek()
    {
      if(top==-1)
        {
          return -1;
        }
        return arr[top];
    }
    
    int size()
    {
      return top+1;
    }
}
