// here call start form begin of arr but linked list is created where end recursion call send back next node address and linked list created form in Reverse mennner(end to start)
// head will be pointing to start value of arr;
class Node
{
    public:
    int data;
    Node *next;
    
    Node(int x)
    {
      data=x;
      next=nullptr;
    }
};

Node* CreateLinkedList(int arr[],int n,int index)
{
  if(index==n)
  {
    return nullptr;
  }

  Node *temp = new Node(arr[index]);
  temp->next = CreateLinkeList(arr,n,index+1);
  return temp;
}

// here head will be pointed to end value of arr
Node* CreateLinkedList(int arr[],int n,int index,Node *prev)
{
    if(index==n)
    {
        return prev;
    }

    Node *temp=new Node(arr[index]);
    temp->next=prev;

    return CreateLinkedlist(arr,n,index+1,temp);
}

