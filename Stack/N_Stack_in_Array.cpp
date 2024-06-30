
// implementation of N-stack in Array

class Node{
    public:
    int index;
    Node *next;
  
    Node(int x)
    {
      index = x;
      nex=null;
    }
};

class NStack
{
    public:
    // Initialize  your data structure
    stack<int> st;
    int *arr;
    Node **top;

    NStack(int N,int S){
        arr = new int[S];
        top=new Node*[N];
        for(int i=0;i<N;i++){
          top[i]=null;
        }
        for(int i=0;i<S;i++){
          st.push(i);
        }
    }

    bool push(int x,int m)
    {
        if(st.empty(){return 0;}
      
        arr[st.top()]=x;
        Node *temp = new Node(st.top());
        temp->next = top[m-1];
        top[m-1]=temp;
        st.pop();
        return 1
    }

    int pop(int m)
    {
        if(top[m-1]==NULL){return -1;}
      
        int element=arr[top[m-1]->index];
        st.push(top[m-1]->index);
        top[m-1]=top[m-1]->next;
        
        return element;
    }
};
